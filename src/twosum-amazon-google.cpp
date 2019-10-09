#include<vector>
#include<fstream>   
#include<iostream>

// Given an int array nums and an int target. Find two integers in nums such that the sum is closest to target.

/*
    Input: nums = [1, 2, 3, 4, 5], target = 10
    Output: [4, 5]

    Input: nums= [-1, 2, 1, -4], target = 4
    Output: [2, 1]
*/

using namespace std;

ostream& operator<<(ostream& s, const vector<int>& input) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for(auto item : input) {
        s << comma << item; 
        comma[0] = ',';
    }
    s.put(']');
    return s;
}

// check if the sum of sorted max and min is smaller of greater than the target.
// if smaller be ready to consider a bigger value lo++
// if larger consider a lower value hi--

vector<int> twosum(vector<int>& arr, int target) {
    vector<int> ret(2);

    sort(arr.begin(), arr.end());

    int min = INT_MAX;
    for(int lo = 0, hi = arr.size() - 1; lo < hi;) {
        int diff = target - (arr[lo] + arr[hi]);
        if(diff > 0) {
            if(diff < min) {
                min = diff;
                ret[0] = arr[lo];
                ret[1] = arr[hi];
            }
            lo++;
        }
        else if(diff < 0) {
            hi--;
        }
        else {
            ret[0] = arr[lo];
            ret[1] = arr[hi];
            break;
        }
        
    } 
    return ret;
}

int main () {
    vector<int> arr = {90, 85, 75, 60, 120, 150, 125};
    int target = 220;
    auto ret = twosum(arr, target);
    
    cout << ret << endl;
    return 0;
}
