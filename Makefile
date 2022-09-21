# mingw32-make

# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

chapter_1 = .\cracking_the_coding_interview\1_array-and-string
chapter_2 = .\cracking_the_coding_interview\2_linked-list
chapter_3 = .\cracking_the_coding_interview\3_stacks-and-queues
chapter_4 = .\cracking_the_coding_interview\4_trees-and-graphs
chapter_5 = .\cracking_the_coding_interview\5_bit-manipulation

name = 5.6_conversion

DIR = $(chapter_5)
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