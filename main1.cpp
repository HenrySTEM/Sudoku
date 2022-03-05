#include <iostream>
#include <vector>
#include <chrono>
#include "Standard.h"
using namespace std::chrono;

int main(){
    string s; cin >> s;
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
    auto start = high_resolution_clock::now();
    if(s == "ei") simple(x);
    if(s == "er") recurse(x);
    if(s == "si") backtrack(x);
    if(s == "sr") backtrack_recurse(x);
    auto stop = high_resolution_clock::now();
    // cout << "Solved Sudoku: " << endl;
    // for(int i = 0; i < 81; ++i){
    //     cout << x.term(i);
    //     if(i % 9 == 8) cout << endl;
    // }
    //cout << x << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    long double time = duration.count();
    cout << time/(1e3) << endl;
}