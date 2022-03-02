CXX = g++

FLAGS = -Wall -Werror -pedantic --std=c++11 -g

sudoku.exe: Standard.cpp main.cpp
	$(CXX) $(FLAGS) $^ -o $@

xv.exe: XV.cpp main.cpp
	$(CXX) $(FLAGS) $^ -o $@

ineq.exe: ineq.cpp main.cpp
	$(CXX) $(FLAGS) $^ -o $@