SOURSE = main.py

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET = main.exe
else
	RM = rm
	TARGET = main
endif

run:
	python ./$(TARGET)