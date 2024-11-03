#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool rotateString(string str, string goal) {
        if(str.size() != goal.size())
            return false;

        str += str;
        if(str.find(goal) != string::npos)
            return true;

        return false;
    }
};