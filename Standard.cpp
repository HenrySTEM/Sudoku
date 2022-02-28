#include <vector>
#include "Standard.h"
#include <stack>
#include <cassert>
using namespace std;

Sudoku::Sudoku(){
    nums = vector<vector<int>>(9,vector<int>(9,0));
}

Sudoku::Sudoku(const vector<vector<int>>& in){
    nums = in;
}

vector<int>& Sudoku::operator[](int i){
    return nums[i];
}

int& Sudoku::term(int i){
    return nums[i/9][i%9];
}

ostream& operator<<(ostream& os, Sudoku &s){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout << s[i][j];
        }
        cout << endl;
    }
    return os;
}

// Check if the number in position x works with the sudoku.
// THIS IS THE MAIN DIFFERENCE BETWEEN VARIANTS
bool works(Sudoku& s, int x){
    // Get row and column numbers
    int row = x/9;
    int col = x%9;
    // Check lines
    for(int i = 0; i < 9; ++i){
        if(i != row){
            if(s[i][col] == s[row][col]) return false;
        }
        if(i != col){
            if(s[row][i] == s[row][col]) return false;
        }
    }
    // Check 3x3 box
    int boxr = row/3;
    int boxc = col/3;
    boxr *= 3; boxc *= 3;
    for(int i = boxr; i < boxr + 3; ++i){
        for(int j = boxc; j < boxc + 3; ++j){
            if(i != row || j != col){
                if(s[row][col] == s[i][j]) return false;
            }
        }
    }
    // Works
    return true;
}

vector<vector<int>> possibles(Sudoku &s){
    // Initialize output vector to 81
    vector<vector<int>> ans(81);

    for(int i = 0; i < 81; ++i){
        // If already filled in, only one possible value
        if(s.term(i) != 0){
            ans[i].push_back(s.term(i));
            continue;
        }

        for(int j = 1; j <= 9; ++j){
            s.term(i) = j;
            if(works(s,i)) ans[i].push_back(j);
        }
        s.term(i) = 0;
    }
    return ans;
}

Sudoku simple(Sudoku in){
    // DFS stack containing pairs. 
    // Each pair is {cell index in empty_cells , current value of cell}
    stack<pair<int,int>> path;
    // Vector containing all the empty cells.
    vector<int> empty_cells;
    for(int i = 0; i < 81; ++i){
        if(in.term(i) == 0){
            empty_cells.push_back(i);
        }
    }
    // Current index in empty_cells
    int i = 0;
    // If already solved, return
    if(empty_cells.size() == 0) return in;
    // Add things for i = 0
    path.push({i,1});
    in.term(empty_cells[i]) = 1;

    while(true){
        // If stack is empty, no solution. 
        if(i < 0){
            assert(false);
            return Sudoku();
        }
        // If the most recent placement works
        if(works(in,empty_cells[i])){
            // If we are done, finish
            if((unsigned int)i == empty_cells.size()){
                return in;
            }
            // If we are not done, go to the next empty cell
            else{
                ++i;
                path.push({i,1});
                in.term(empty_cells[i]) = 1;
                continue;
            }
        }
        // Most recent placement doesn't work
        else{
            // Still more possibilities: keep going
            if(path.top().second < 9){
                ++path.top().second;
                ++in.term(empty_cells[i]);
                continue;
            }
            // No more possibilities: branch doesn't work. Go back.
            else{
                while(path.top().second == 9){
                    in.term(empty_cells[i]) = 0;
                    --i;
                    path.pop();
                    // If no solution
                    if(i < 0){
                        assert(false);
                        return Sudoku();
                    }
                }
                ++path.top().second;
                ++in.term(empty_cells[i]);
            }   
        }
    }
    // Never get here
    return Sudoku();
}

Sudoku backtrack(Sudoku in){
    auto v = possibles(in);
    for(int i = 0; i < 81; ++i){
        
    }
}