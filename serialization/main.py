from enum import Enum
import struct


class Alignment(Enum):
    HORIZONTAL = 1
    VERTICAL = 2


class Widget():
    def __init__(self, parent):
        self.parent = parent
        self.childrens = []
        if self.parent is not None:
            self.parent.add_children(self)

    def add_children(self, children: "Widget"):
        self.childrens.append(children)

    def to_binary(self):
        classname = self.__class__.__name__.encode()
        result = struct.pack("i", len(classname)) + classname
        if classname.decode() == 'Layout':
            result += struct.pack("i", self.alignment.value)
        elif classname.decode() == "LineEdit":
            result += struct.pack("i", self.max_length)
        elif classname.decode() == "ComboBox":
            items = [str(item) for item in self.items]
            bstr = ';'.join(items).encode()
            result += struct.pack("i", len(bstr)) + bstr
        elif classname.decode() == "MainWindow":
            result += struct.pack("i", len(self.title.encode())) + self.title.encode()
        data = b"".join([child.to_binary() for child in self.childrens])
        result += struct.pack("i", len(data)) + data
        return result

    @classmethod
    def from_binary(cls, data, parent=None):
        classname_len = struct.unpack("i", data[:4])[0]
        current_size = 4
        classname = data[current_size:current_size + classname_len].decode()
        current_size += classname_len
        property_len = struct.unpack("i", data[current_size:current_size + 4])[0]
        current_size += 4
        property = data[current_size:current_size + property_len].decode()
        current_size += property_len
        if classname == 'MainWindow':
            root = cls(property)
        elif classname == 'Layout':
            current_size -= property_len
            root = Layout(parent, property_len)
        elif classname == 'LineEdit':
            current_size -= property_len
            root = LineEdit(parent, property_len)
        elif classname == 'ComboBox':
            root = ComboBox(parent, property)
        children_len = struct.unpack("i", data[current_size:current_size + 4])[0]
        current_size += 4
        data_children = data[current_size:]
        cursor = 0
        while cursor < children_len:
            child, child_cursor = root.from_binary(data_children[cursor:], parent=root)
            cursor += child_cursor
        return root, current_size + cursor

    def __str__(self):
        return f"{self.__class__.__name__}{self.childrens}"

    def __repr__(self):
        return str(self)


class MainWindow(Widget):
    def __init__(self, title: str):
        super().__init__(None)
        self.title = title


class Layout(Widget):
    def __init__(self, parent, alignment: Alignment):
        super().__init__(parent)
        self.alignment = alignment


class LineEdit(Widget):
    def __init__(self, parent, max_length: int=10):
        super().__init__(parent)
        self.max_length = max_length


class ComboBox(Widget):
    def __init__(self, parent, items):
        super().__init__(parent)
        self.items = items


app = MainWindow("Application")
layout1 = Layout(app, Alignment.HORIZONTAL)
layout2 = Layout(app, Alignment.VERTICAL)

edit1 = LineEdit(layout1, 20)
edit2 = LineEdit(layout1, 30)

box1 = ComboBox(layout2, [1, 2, 3, 4])
box2 = ComboBox(layout2, ["a", "b", "c"])

print(app)

bts = app.to_binary()
print(f"Binary data length {len(bts)}")

new_app = MainWindow.from_binary(bts)
print(new_app)
