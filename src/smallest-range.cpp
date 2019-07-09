//
//  smallest-range.cpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/8/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#include "smallest-range.hpp"

int main() {
    std::vector<int> res;
    std::vector<std::vector<int>> nums = {
        { 4, 10, 15, 24, 26 },
        { 0, 9, 12, 20 },
        { 5, 18, 22, 30 }
    };
    res = smallestRangePQ(nums);
    for(auto x : res)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
