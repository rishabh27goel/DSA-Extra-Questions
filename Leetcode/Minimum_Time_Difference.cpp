#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTime(string &str) {
        int hrs = (str[0]-'0') * 10 + (str[1]-'0');
        int min = (str[3]-'0') * 10 + (str[4]-'0');
        return (hrs * 60) + min;
    }   

    // Here we need to think about the circular array
    // Check all the pairs from 0 to n 
    // And check the last element with first element
    int findMinDifference(vector<string>& timePoints) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        vector<int> timeCheck(1440, 0);
        for(int j = 0; j < timePoints.size(); j++) {
            timeCheck[findTime(timePoints[j])]++;
        }

        int minMin = 1500;
        int startTime = -1;
        int prevTime = -1;

        for(int j = 0; j < 1440; j++) {
            if(timeCheck[j] == 0)   continue;
            if(timeCheck[j] >= 2)   return 0;

            if(startTime == -1)  startTime = j;
            if(prevTime != -1)   minMin = min(j - prevTime, minMin);
            prevTime = j;
        }

        minMin = min(startTime + 1440 - prevTime, minMin);
        return minMin;
    }
};