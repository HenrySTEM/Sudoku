CXX = g++

FLAGS = -Wall -Werror -pedantic --std=c++11 -g

sudoku.exe: Standard.cpp main.cpp
	$(CXX) $(FLAGS) $^ -o $@