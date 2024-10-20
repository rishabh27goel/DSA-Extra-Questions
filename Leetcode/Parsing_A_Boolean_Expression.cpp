#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findBoolHelper(int n, string &str, int &idx) {
        char currChar = str[idx++];
        if(currChar == 't')   return true;
        if(currChar == 'f')   return false;

        if(currChar == '!') {
            idx++;  // Skip '('
            bool expValue = findBoolHelper(n, str, idx);
            idx++;  // Skip ')'
            return !expValue; 
        }

        // AND and OR expressions
        vector<bool> expValues;
        idx++;  // Skip '('

        while(str[idx] != ')') {
            if(str[idx] == ',') {
                idx++;
            }
            else {
                expValues.push_back(findBoolHelper(n, str, idx));
            }
        }
        
        idx++;  // Skip ')'
        if(currChar == '&') {
            for(bool value : expValues)
                if(!value)  return false;

            return true;
        }
        
        if(currChar == '|') {
            for(bool value : expValues)
                if(value)  return true;

            return false;
        }

        return false;
    }

    bool parseBoolExpr(string expression) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = expression.size();
        int idx = 0;

        return findBoolHelper(n, expression, idx);
    }
};