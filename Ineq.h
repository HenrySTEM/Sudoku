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
    Sudoku(const vector<vector<int>>& in, const vector<vector<char>>& h, const vector<vector<char>>& v);

    // Gets the ith term of the sudoku
    int& term(int i);

    char& horizterm(int i);

    char& vertterm(int i);

    vector<vector<char>> horiz;
    vector<vector<char>> vert;

private:
    vector<vector<int>> nums;
};

// Prints sudoku
ostream& operator<<(ostream& os, Sudoku &s);

// Returns a list of lists, each containing the possible numbers in that cell.
vector<pair<int,vector<int>>> possibles(Sudoku &s);

// Returns false if the number at (row,col) violates the sudoku
// The most important function.
bool works(Sudoku& s, int x);

// Simple solution (backtracking - naive)
Sudoku simple(Sudoku in);

// Similar to the Simple solution, but implemented recursively.
// https://www.geeksforgeeks.org/sudoku-backtracking-7/
Sudoku recurse(Sudoku in);

// Helps with the recurse function
pair<Sudoku,bool> recurse_helper(Sudoku& in, vector<int>& empty_cells, unsigned int curpos);

// Solves a sudoku with more optimized backtracking
// Detailed in https://arxiv.org/pdf/1203.2295.pdf
Sudoku backtrack(Sudoku in);

// Like the backtrack function, but recursive.
Sudoku backtrack_recurse(Sudoku in);

// Helper for backtrack_recurse
pair<Sudoku,bool> backtrack_recurse_helper(Sudoku& in, vector<pair<int,vector<int>>>& allowed, unsigned int curpos);

// Solves a sudoku with the Dancing Links
// Detailed in https://arxiv.org/pdf/cs/0011047.pdf
Sudoku dancing_links(Sudoku in);

#endif // STANDARD_H