CXX = g++

FLAGS = -Wall -Werror -pedantic --std=c++11 -g

sudoku.exe: Standard.cpp main1.cpp
	$(CXX) $(FLAGS) $^ -o $@

xv.exe: XV.cpp main2.cpp
	$(CXX) $(FLAGS) $^ -o $@

ineq.exe: ineq.cpp main3.cpp
	$(CXX) $(FLAGS) $^ -o $@