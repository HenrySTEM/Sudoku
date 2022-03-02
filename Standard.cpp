#include <vector>
#include "Standard.h"
#include <stack>
#include <cassert>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

Sudoku::Sudoku(){
    nums = vector<vector<int>>(9,vector<int>(9,0));
}

Sudoku::Sudoku(const vector<vector<int>>& in){
    nums = in;
}

int& Sudoku::term(int i){
    return nums[i/9][i%9];
}

ostream& operator<<(ostream& os, Sudoku &s){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout << s.term(9*i + j);
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
            if(s.term(9*i + col) == s.term(9*row + col)) return false;
        }
        if(i != col){
            if(s.term(9*row + i) == s.term(9*row + col)) return false;
        }
    }
    // Check 3x3 box
    int boxr = row/3;
    int boxc = col/3;
    boxr *= 3; boxc *= 3;
    for(int i = boxr; i < boxr + 3; ++i){
        for(int j = boxc; j < boxc + 3; ++j){
            if(i != row || j != col){
                if(s.term(9*row + col) == s.term(9*i + j)) return false;
            }
        }
    }
    // Works
    return true;
}

/*****************************************SIMPLE*********************************************/

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
            if((unsigned int)i + 1 == empty_cells.size()){
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

/*****************************************RECURSE*********************************************/

Sudoku recurse(Sudoku in){
    vector<int> empty_cells;
    for(int i = 0; i < 81; ++i){
        if(in.term(i) == 0){
            empty_cells.push_back(i);
        }
    }
    Sudoku temp = in;
    return recurse_helper(temp,empty_cells,0).first;
}

pair<Sudoku,bool> recurse_helper(Sudoku &in, vector<int>& empty_cells, unsigned int curpos){
    if(curpos == empty_cells.size()){
        return {in,true};
    }
    for(int i = 1; i <= 9; ++i){
        in.term(empty_cells[curpos]) = i;
        if(works(in,empty_cells[curpos])){
            auto x = recurse_helper(in,empty_cells,curpos + 1);
            if(x.second == true){
                return x;
            }
        }
    }
    in.term(empty_cells[curpos]) = 0;
    return {Sudoku(),false};
}

/*****************************************BACKTRACK*********************************************/

vector<pair<int,vector<int>>> possibles(Sudoku &s){
    vector<int> nums;
    for(int i = 0; i < 81; ++i){
        if(s.term(i) == 0){
            nums.push_back(i);
        }
    }
    // Initialize output vector to 81
    vector<pair<int,vector<int>>> ans;

    for(int i : nums){
        vector<int> temp;
        for(int j = 1; j <= 9; ++j){
            s.term(i) = j;
            if(works(s,i)) temp.push_back(j);
        }
        s.term(i) = 0;
        ans.push_back({i,temp});
    }
    return ans;
}

struct comp{
    bool operator()(pair<int,vector<int>>& lhs, pair<int,vector<int>>& rhs){
        return (lhs.second.size() < rhs.second.size());
    }
};

Sudoku backtrack(Sudoku in){
    auto allowed = possibles(in);
    sort(allowed.begin(),allowed.end(),comp());
    // DFS stack containing pairs. 
    // Each pair is {cell index in empty_cells , current index of cell}

    stack<pair<int,int>> path;
    // Current index
    int i = 0;
    // Add things for i = 0
    path.push({i,0});
    in.term(allowed[i].first) = allowed[i].second[0];

    while(true){
        // If stack is empty, no solution. 
        if(i < 0){
            assert(false);
            return Sudoku();
        }
        // If the most recent placement works
        if(works(in,allowed[i].first)){
            // If we are done, finish
            if((unsigned int)i + 1 == allowed.size()){
                return in;
            }
            // If we are not done, go to the next empty cell
            else{
                ++i;
                path.push({i,0});
                in.term(allowed[i].first) = allowed[i].second[0];
                continue;
            }
        }
        // Most recent placement doesn't work
        else{
            // Still more possibilities: keep going
            if((unsigned int)(path.top().second) + 1 < allowed[path.top().first].second.size()){
                ++path.top().second;
                in.term(allowed[i].first) = allowed[i].second[path.top().second];
                continue;
            }
            // No more possibilities: branch doesn't work. Go back.
            else{
                while((unsigned int)(path.top().second + 1) == allowed[path.top().first].second.size()){
                    in.term(allowed[i].first) = 0;
                    --i;
                    path.pop();
                    // If no solution
                    if(i < 0){
                        assert(false);
                        return Sudoku();
                    }
                }
                ++path.top().second;
                in.term(allowed[i].first) = allowed[i].second[path.top().second];
            }   
        }
    }
    // Never get here
    return Sudoku();
}

/********************************BACKTRACK_RECURSE*************************************/

Sudoku backtrack_recurse(Sudoku in){
    vector<pair<int,vector<int>>> allowed = possibles(in);
    sort(allowed.begin(),allowed.end(),comp());
    Sudoku temp = in;
    return backtrack_recurse_helper(temp,allowed,0).first;
}

pair<Sudoku,bool> backtrack_recurse_helper(Sudoku& in, vector<pair<int,vector<int>>>& allowed, unsigned int curpos){
    if(curpos == allowed.size()){
        return {in,true};
    }
    for(int i : allowed[curpos].second){
        in.term(allowed[curpos].first) = i;
        if(works(in,allowed[curpos].first)){
            auto x = backtrack_recurse_helper(in,allowed,curpos + 1);
            if(x.second == true){
                return x;
            }
        }
    }
    in.term(allowed[curpos].first) = 0;
    return {Sudoku(),false};
}

/*****************************************DANCING_LINKS*********************************************/

