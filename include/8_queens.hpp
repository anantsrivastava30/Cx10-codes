//
//  8_queens.hpp
//  cx10-codes
//
//  Created by Anant Srivastava on 10/04/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#ifndef __queens_hpp__
#define __queens_hpp__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <unistd.h>

using namespace std;


ostream& operator<<(ostream& s, const vector<char>& v){
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (auto item : v) {
        s << comma << item;
        comma[0] = ',';
    }
    return s << ']';
}

class Board {
public:
    vector<vector<char>> grid;
    int shape;

    Board(int size): grid(size ,vector<char>(size, '_')), shape(size) {};
    ~Board() {};
    
    void toString();
    bool isSafe(int row, int col);
    void place(int row, int col);
    void remove(int row, int col);
};

void Board::toString() {
    system("clear");
    for(auto row : Board::grid)
        cout << row << endl;
    
    cout << endl;
    usleep(100000);
}

void Board::place(int row, int col) {
    Board::grid[row][col] = 'Q';
}

void Board::remove(int row, int col) {
    Board::grid[row][col] = '_';
}

bool Board::isSafe(int row, int col) {
    for(int i = 0; i < col; i++) {
        if(Board::grid[row][i] == 'Q') return false;
    }

    for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) 
        if(Board::grid[i][j] == 'Q') return false;
    
    for(int i = row, j = col; i < shape && j >= 0; ++i, --j) 
        if(Board::grid[i][j] == 'Q') return false;

    return true;
}

#endif // queens_hpp
