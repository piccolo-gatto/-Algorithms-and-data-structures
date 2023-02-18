CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
FIRST_SOURCES = create_data.cpp
SECOND_SOURCES = get_angle.cpp

number = 1000
name = out.txt
res_name = result.txt

ifeq ($(OS), Windows_NT)
	RM = del
	FIRST_TARGET = create_data.exe
	SECOND_TARGET = get_angle.exe
else
	RM = rm
	FIRST_TARGET = create_data
	SECOND_TARGET = get_angle
endif

create_data:
	$(CC) $(CFLAGS) -o $(FIRST_TARGET) $(FIRST_SOURCES)

get_angle:
	$(CC) $(CFLAGS) -o $(SECOND_TARGET) $(SECOND_SOURCES)

clean:
	echo $(OS)
	$(RM) $(FIRST_TARGET)
	$(RM) $(name)
	$(RM) $(SECOND_TARGET)
	$(RM) $(res_name)

run: create_data get_angle
	$(FIRST_TARGET) $(number) $(name)
	$(SECOND_TARGET) $(name) $(res_name)