# mingw32-make

# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

chapter_1 = .\cracking_the_coding_interview\chapter_1
chapter_2 = .\cracking_the_coding_interview\chapter_2
chapter_3 = .\cracking_the_coding_interview\chapter_3
chapter_4 = .\cracking_the_coding_interview\chapter_4

name = 4.11_random_node

DIR = $(chapter_4)
FILE = $(name)

# The build target 
compile: $(DIR)\$(FILE).o
	$(CC) $(CFLAGS) $(DIR)\$(FILE).o -o compile
	@echo --------------------Output Compile.exe--------------------
	compile.exe
	
clean:
	-del $(DIR)\*.o *.exe $(DIR)\*.exe 
#	-rm -fR $(DIR)\*.o *.exe

.PHONY: clean