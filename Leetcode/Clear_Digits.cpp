#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string clearDigits(string str) {
        int n = str.size();
    
        string result = "";
        for(int j = 0; j < n; j++) {
            if(str[j] >= '0' && str[j] <= '9')
                result.pop_back();
            else 
                result.push_back(str[j]);
        }
        return result;
    }
};