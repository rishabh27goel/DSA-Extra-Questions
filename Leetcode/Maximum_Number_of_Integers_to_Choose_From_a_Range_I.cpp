#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> track(n + 1, false);
        for(int i = 0; i < banned.size(); i++) {
            if(banned[i] > n)   
                continue;

            track[banned[i]] = true;
        }

        int numCount = 0;
        for(int j = 1; j <= n; j++) {
            if(track[j])    continue;

            if(maxSum - j >= 0) {
                maxSum -= j;
                numCount++;
            }
            else    
                break;
        }

        return numCount;
    }
};