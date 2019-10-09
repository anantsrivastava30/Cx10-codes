//
//  word-break-II.hpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/10/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#ifndef word_break_II_hpp
#define word_break_II_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> wordBreak(string s, vector<string>& wordDict);

/*
 s = "pineapplepenapple"
 wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 Output:
 [
 "pine apple pen apple",
 "pineapple pen apple",
 "pine applepen apple"
 ]
 */

unordered_map<string, vector<string>> m;

vector<string> combine(string word, vector<string> prev){
    for(int i=0;i<prev.size();++i){
        prev[i]+=" "+word;
    }
    return prev;
}

vector<string> wordBreak(string s, unordered_set<string>& dict) {
    if(m.count(s)) return m[s]; //take from memory
    vector<string> result;
    if(dict.count(s)){ //a whole string is a word
        result.push_back(s);
    }
    for(int i=1;i<s.size();++i){
        string word=s.substr(i);

        if(dict.count(word)){
            cout << "word " << word << ", rem ";
            string rem=s.substr(0,i);
            cout << rem << endl;
            vector<string> prev=combine(word,wordBreak(rem,dict));
            result.insert(result.end(),prev.begin(), prev.end());
        }
    }
    m[s]=result; //memorize
    return result;
    }
#endif
