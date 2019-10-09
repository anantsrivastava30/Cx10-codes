//
//  backtracking.cpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/14/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#include "backtracking.hpp"

int subArrayOfSum() {
    int n = 7;
    int a[n+1];
    int target {8};

    vector<vector<int>> ans;

    vector<int> arr = {10,1,2,7,6,1,5};
    cout << arr << endl;
    backtrack(a, arr, ans, 0, n);
    
    for (auto line : ans) {
        int sum = accumulate(line.begin(), line.end(), 0);
        if (sum == target) {
            std::cout << line << std::endl;
        }
    }
    return 0;
}

int main() {
    cout << "the sub array of vector ";
    subArrayOfSum();

    cout << "permutation of my name" << endl;
    permutation("anant");

    int n = 3;
    cout << "all " << n << " digit binary numbers" << endl;

    printBinary(n);  

    cout << "all " << n << " digit decimal numbers\n" << endl;
    printDecimal(n-1);  
    
    return 0;
}
