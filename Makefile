# mingw32-make

# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

DIR = C:\Users\belvs\Desktop\FedericoBruzzone\data_structure_CCI\cracking_the_coding_interview\chapter_3

SHELL=cmd

# The build target 
compile: $(DIR)\3.6_animal_shelter.o
	$(CC) $(CFLAGS) $(DIR)\3.6_animal_shelter.o -o compile
	@echo --------------------Output Compile.exe--------------------
	compile.exe
	
clean: 
	-del -fR $(DIR)\*.o *.exe
.PHONY: clean