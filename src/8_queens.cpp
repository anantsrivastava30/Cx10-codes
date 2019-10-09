//
//  8_queens.cpp
//  cx10-codes
//
//  Created by Anant Srivastava on 10/05/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#include "8_queens.hpp"

bool nQueensHelper(Board &board, int col) {
    if(col >= board.shape) {
        board.toString();
        return true;
    }
    else {
        for(int i = 0; i < board.shape; i++) {
            if(board.isSafe(i ,col)) {
                board.place(i, col);
                board.toString();
                bool finished = nQueensHelper(board, col+1);
                if(finished)
                    return true;

                board.remove(i, col);
            }
        }
    }
    return false;
}

void nQueens(Board &board) {
    nQueensHelper(board, 0);
}

int main() {
    
    Board x = Board(8);

    nQueens(x);
    return 0;
}
