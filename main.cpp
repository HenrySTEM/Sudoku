#include <iostream>
#include <vector>
#include "Standard.h"

int main(){
    vector<vector<int>> a(9,vector<int>(9,0));
    char c;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >> c;
            if(c <= '0' || c > '9') a[i][j] = 0;
            else a[i][j] = (int)(c - '0');
        }
    }
    Sudoku x(a);
    x = simple(x);
    for(int i = 0; i < 81; ++i){
        cout << x.term(i);
        if(i % 9 == 8) cout << endl;
    }
}