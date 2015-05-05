all: solution

grader.o: grader.cpp
	g++ -DEVAL -O2 -o grader.o -c grader.cpp

solution: solution.cpp grader.o LTiling.h
	g++ -DEVAL -static -O2 -o solution solution.cpp grader.o
