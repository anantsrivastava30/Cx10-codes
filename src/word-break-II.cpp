//
//  word-break-II.cpp
//  cx10-codes
//
//  Created by Anant Srivastava on 7/10/19.
//  Copyright © 2019 Anant Srivastava. All rights reserved.
//

#include "word-break-II.hpp"

ostream& operator<<(ostream& s, const unordered_set<string>& v){
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (auto item : v) {
        s << comma << item;
        comma[0] = ',';
    }
    return s << ']';
}

ostream& operator<<(ostream& s, const vector<string>& v){
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (auto item : v) {
        s << comma << item;
        comma[0] = ',';
    }
    return s << ']';
}

using namespace std;

int main () {
    vector<string> validStrings;
    
    string str = "catsanddog";
    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    
    cout << "elements :" << wordDict << endl;
    
    validStrings = wordBreak(str, wordDict);
    cout << "result :" << validStrings << endl;

//    for (auto str : validStrings) {
//        cout << str << endl;
//    }
    
    return 0;
}
