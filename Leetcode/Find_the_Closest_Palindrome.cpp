#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long getPalindromeHelper(long long leftNum, int add, int length) {
        leftNum += add;
        string right = to_string(leftNum);

        if(length % 2 == 0) {
            reverse(right.begin(), right.end());
            return stoll(to_string(leftNum) + right);
        }
        else {
            right.pop_back();
            reverse(right.begin(), right.end());
            return stoll(to_string(leftNum) + right);
        }
    }

    string nearestPalindromic(string str) {
        long long palLen = str.size();
        vector<long long> candidates;

        // Based on the length
        candidates.push_back(pow(10, palLen) + 1);
        candidates.push_back(pow(10, palLen - 1) - 1);

        // Based on the left half [left, left - 1, left + 1]
        string leftHalf = str.substr(0, (palLen + 1) / 2);
        long long leftNum = stoll(leftHalf);        

        candidates.push_back(getPalindromeHelper(leftNum, 0, palLen));
        candidates.push_back(getPalindromeHelper(leftNum, -1, palLen));
        candidates.push_back(getPalindromeHelper(leftNum, 1, palLen));
  
        long long palNum = stoll(str);
        long long closestNum = -1;
        long long closest = INT_MAX;

        for(auto &possible : candidates) {
            if(possible == palNum)
                continue;

            if(abs(possible - palNum) < closest) {
                closest = abs(possible - palNum);
                closestNum = possible;
            }
            else if(abs(possible - palNum) == closest) {
                closestNum = min(possible, closestNum);
            }
        }

        return to_string(closestNum);
    }
};