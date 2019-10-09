//
//  backtracking.hpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/14/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#ifndef backtracking_hpp
#define backtracking_hpp

#define MAXCANDIDATES 2

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;
bool finished = false;

bool is_a_solution(int a[], int k, int n) {
    return (k == n);
}

ostream& operator<<(ostream& s, const vector<int>& v){
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (auto item : v) {
        s << comma << item;
        comma[0] = ',';
    }
    return s << ']';
}

void process_solution(int a[], vector<int> arr, vector<vector<int>> &ans, int k) {
    int i;
    vector<int> temp;
    for (i = 1; i <= k; i++) {
        if(a[i] == true) {
            temp.push_back(arr[i - 1]);
        }
    }
    ans.push_back(temp);
}
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void backtrack(int a[], vector<int> &arr, vector<vector<int>> &ans, int k, int input) {
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    
    if(is_a_solution(a, k, input))
        process_solution(a, arr, ans, k);
    else {
        k++;
        construct_candidates(a, k, input, c, &ncandidates);
        for (i = 0; i<ncandidates; i++) {
            a[k] = c[i];
            backtrack(a, arr, ans, k,input);
            if(finished) return;
        }
    }
}

void permutationHelper(string s, string choice, vector<string> &Set) {
    if(s.empty()) {
        Set.push_back(choice);
    } else {
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            choice += c;
            s.erase(i ,1);
            permutationHelper(s, choice, Set);

            s.insert(i, 1, c);
            choice.pop_back();
        }
    }
}

void permutation(string name) {
    // name : Anant
    vector<string> Set;
    permutationHelper(name, "", Set);
    for(int i = 0; i < Set.size(); i++) {
        cout << Set[i] << "    ";
        if(i % 8 == 0)
            cout << endl;
    }
    cout << endl;
}

void indent(int count) {
    for(int i = 0; i < count; i++)
        cout << " ";
}
void printBinary(int count, string prefix = "") {
    // indent(prefix.length());
    // cout << "printBinary(" << count << ", " << prefix << ")" << endl;
    if(count == 0) {
        cout << prefix << endl;
    } else {
        printBinary(count - 1, prefix + "0");
        printBinary(count - 1, prefix + "1");
    }   
}

void printDecimal(int count, string prefix = "") {
    cout << "printDecimal(" << count << ", " << prefix << ")" << endl;
    if(count == 0) {
        cout << prefix << endl;
    } else {
        for(int i = 0; i < 10; i++) {
            printDecimal(count - 1, prefix + to_string(i));
        } 
    }   
}
#endif /* backtracking_hpp */
