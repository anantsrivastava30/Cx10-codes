//
//  spiral-matrix-2.hpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/9/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#ifndef spiral_matrix_hpp
#define spiral_matrix_hpp


#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n);
std::vector<std::vector<int>> spiralMatrixIII(int R, int C, int r0, int c0);
void print_matrix(std::vector<std::vector<int>> &A);

void print_matrix(std::vector<std::vector<int>> &A){
    for(auto row : A){
        for(auto val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> generateMatrix(int n) {
    // initialize 2 d vector
    std::vector<std::vector<int>> ans (n ,std::vector<int>(n));
    
    int stride = n, control = 1, dir = 0, val = 1;
    
    int xdir [] = {1, 0, -1, 0};
    int ydir [] = {0, 1, 0, -1};
    
    int x = -1, y = 0;
    
    while(true) {
        if(stride == 0)
            break;
        
        for(int i = 0; i < stride; i++) {
            x += xdir[dir];
            y += ydir[dir];
            ans[y][x] = val;
            ++val;
        }
        if(control & 1)
            --stride;
        
        control++;
        dir = (++dir)%4;
    }
    return ans;
}

std::vector<std::vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    int rpos = r0, cpos = c0, go = 1, dir = 0;
    int ctr = 0, cnt = 0;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    std::vector<std::vector<int>> res;
    
    res.push_back({rpos, cpos});
    ctr++;
    while(ctr < R * C) {
        for(int i = 1; i <= go; i++) {
            rpos += dr[dir];
            cpos += dc[dir];
            if(rpos >= 0 && rpos < R && cpos >= 0 && cpos < C) {
                res.push_back({rpos, cpos});
                ctr++;
            }
        }
        
        if (cnt & 1)
            go++;
        
        dir++;
        cnt++;
        dir %= 4;
    }
    return res;
}
#endif /* spiral_matrix_hpp */
