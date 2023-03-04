CC = g++
CFLAGS = -std=c++17 -Wall -pedantic
SOURCE_CPP = map.cpp
SOURCE_PY = dict.py
DRAW_PY = view.py

ifeq ($(OS), Windows_NT)
	RM = rm
	TARGET_CPP = main.exe

else
	RM = rm
	TARGET_CPP = main

endif

all:
	$(CC) $(CFLAGS) -o $(TARGET_CPP) $(SOURCE_CPP)

clean:
	echo $(OS)
	$(RM) $(TARGET_CPP)

run: all
	$(TARGET_CPP)
	python $(SOURCE_PY)
	python $(DRAW_PY)