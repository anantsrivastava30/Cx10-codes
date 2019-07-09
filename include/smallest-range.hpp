//
//  smallest-range.hpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/8/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#ifndef smallest_range_hpp
#define smallest_range_hpp

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

std::vector<int> smallestRangePointer(std::vector<std::vector<int>> &nums);
std::vector<int> smallestRangePQ(std::vector<std::vector<int>> &nums);

/*
 * find the smallest sequence which contains
 * atleast one element from all gives sorted list
 * */
std::vector<int> smallestRangePointer(std::vector<std::vector<int>>& nums) {
    std::vector<int> ret;
    // pointer array for all the lists denotes the position of
    // the probing min or max in each of the lists.
    int *next = new int [nums.size()] ();
    
    // setting the global min and max for the sequence.
    int minx = 0, miny = INT_MAX;
    
    // flag to tell if either of the lists are exhausted.
    bool flag = true;
    
    for (int i = 0; i < nums.size() && flag; i++) {
        for (int j = 0; j < nums[i].size() && flag; j++) {
            // setting min and max index for all the lists.
            // 0 <= min_i <= max_i <= num.lists
            int min_i = 0, max_i = 0;
            for(int k = 0; k < nums.size(); k++) {
                if (nums[min_i][next[min_i]] > nums[k][next[k]])
                    min_i = k;
                if (nums[max_i][next[max_i]] < nums[k][next[k]])
                    max_i = k;
            }
            // set the global range if the current range [f(max_i), f(max_i]
            if (miny - minx > nums[max_i][next[max_i]] - nums[min_i][next[min_i]]) {
                miny = nums[max_i][next[max_i]];
                minx = nums[min_i][next[min_i]];
            }
            next[min_i]++;
            if(next[min_i] == nums[min_i].size())
                flag = false;
        }
    }
    delete [] next;
    ret.insert(ret.end(), {minx, miny});
    return ret;
}


std::vector<int> smallestRangePQ(std::vector<std::vector<int>> &nums) {
    typedef std::vector<int>::iterator itr;
    
    // comparator for the Pqueue
    struct comp {
        bool operator ()(std::pair<itr, itr> left, std::pair<itr, itr> right) {
            return *left.first > *right.first;
        }
    };
    
    int minx = INT_MAX, miny = INT_MIN;
    // qrioriy queue for inseting pairwise begin and end for each row.
    // we will increase the begin one by one for the min row.
    std::priority_queue<std::pair<itr, itr>, std::vector<std::pair<itr, itr>>, comp> queue;
    
    // doing the first sequence here.
    for (auto &row : nums) {
        minx = std::min(minx, row[0]);
        miny = std::max(miny, row[0]);
        queue.push({row.begin(), row.end()});
    }
    
    std::vector<int> ans = {minx, miny};
    while (true) {
        auto curr = queue.top();
        queue.pop();
        
        ++curr.first;
        if (curr.first == curr.second)
            break;
        queue.push(curr);
        
        // selecting min from the min-heap
        minx = *queue.top().first;
        // selecting max from the last max vs the current values for the min row.
        miny = std::max(miny, *curr.first);
        if(miny - minx < ans[1] - ans[0])
            ans = {minx, miny};
    }
    return ans;
}

#endif /* smallest_range_hpp */
