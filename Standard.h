#ifndef STANDARD_H
#define STANDARD_H
#include <iostream>
#include <vector>
using namespace std;

struct Sudoku{
public:
    // Default constructor
    Sudoku();

    // Constructor from a grid
    Sudoku(const vector<vector<int>>& in);

    // Gets the ith row of the sudoku
    vector<int>& operator[](int i);

    // Gets the ith term of the sudoku
    int& term(int i);
private:
    vector<vector<int>> nums;
};

// Prints sudoku
ostream& operator<<(ostream& os, Sudoku &s);

// Returns a list of lists, each containing the possible numbers in that cell.
vector<vector<int>> possibles(Sudoku & s);

// Returns false if the number at (row,col) violates the sudoku
bool works(Sudoku& s, int x);

// Simple solution (backtracking - naive)
Sudoku simple(Sudoku in);

// Solves a sudoku with more optimized backtracking
// Detailed in https://arxiv.org/pdf/1203.2295.pdf
Sudoku backtrack(Sudoku in);

// Solves a sudoku with the markup (pencil-and-paper) strategy
// Also prints a set of steps to os
// Detailed in http://www.ams.org/notices/200904/rtx090400460p.pdf
Sudoku markup(Sudoku in,ostream& os);

// Solves a sudoku with the Dancing Links
// Detailed in https://arxiv.org/pdf/cs/0011047.pdf
Sudoku dancing_links(Sudoku in);

#endif // STANDARD_H