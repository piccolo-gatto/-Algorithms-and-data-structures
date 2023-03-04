from matplotlib import pyplot as plt


cpp = [[], [], []]
py = [[], [], []]


def get_data(file_name, data_list):
	with open(file_name, "r") as file:
		for line in file:
			el = list(map(int, line.split()))
			data_list[0] += [el[0]]
			data_list[1] += [el[1]]
			data_list[2] += [el[2]]

get_data("out_cpp.txt", cpp)
get_data("out_py.txt", py)

ax = plt.subplot(1, 2, 1)
plt.title("График зависимости скорости выполнения \n от количества элементов")
plt.xlabel("Количетсво элементов")
plt.ylabel("Размер, bytes")
plt.plot(cpp[0], cpp[2], label="C++")
plt.plot(py[0], py[2], label="Python")
ax.set_xscale("log")
ax.set_yscale("log")
plt.legend()

ax = plt.subplot(1, 2, 2)
plt.title("График зависимости требуемого объема памяти \n от колличества элементов")
plt.xlabel("Количетсво элементов")
plt.ylabel("Время выполнения, ms")
plt.plot(cpp[0], cpp[1], label="C++")
plt.plot(py[0], py[1], label="Python")
ax.set_xscale("log")
ax.set_yscale("log")
plt.legend()
plt.show()