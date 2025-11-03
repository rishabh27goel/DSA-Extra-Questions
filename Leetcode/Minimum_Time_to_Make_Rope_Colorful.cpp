#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int minCost(string colors, vector<int>& neededTime) {
            int size = colors.size();
    
            int minTimeNeeded = 0;
            int currIdx = 0;
    
            while(currIdx < size) {
                int maxTime = INT_MIN;
                int totalTime = 0;
    
                char currChar = colors[currIdx];
                while(currIdx < size && currChar == colors[currIdx]) {
                    maxTime = max(maxTime, neededTime[currIdx]);
                    totalTime += neededTime[currIdx];
                    currIdx++;
                }
                minTimeNeeded += (totalTime - maxTime);
            }
            return minTimeNeeded;
        }
    };