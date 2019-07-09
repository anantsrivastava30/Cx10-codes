//
//  spiral-matrix-2.cpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/9/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#include "spiral-matrix.hpp"

using namespace std;

int main(void) {
    int n = 4;
    cout << "generate matrix of size" << n << endl;
    
    // Generate spiral matrix
    vector<vector<int>> matrix = generateMatrix(n);
    
    print_matrix(matrix);
    
    // Return a list of coordinates representing the positions of the grid in the
    // order they were visited.
    vector<vector<int>> spiral3 = spiralMatrixIII(5, 6, 1, 4);
    
    print_matrix(spiral3);
    
    return 0;
}
