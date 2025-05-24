#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // If number of nodes which can be increased is even - totalSum is fine
        // Otherwise, check for minimum difference with all possible changes 
        // (a - b, b - a) find the minimum difference 
        long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            int size = nums.size();
    
            long long totalSum = 0;
            long minNum = INT_MAX;
            int count = 0;
    
            for(int currIdx = 0; currIdx < size; currIdx++) {
                long currNum = nums[currIdx];
                if((currNum ^ k) > currNum) {
                    totalSum += (currNum ^ k);
                    minNum = min(minNum, (currNum ^ k) - currNum);
                    count++;
                }
                else {
                    totalSum += currNum;
                    minNum = min(minNum, currNum - (currNum ^ k));
                }
            }
    
            if(count % 2 == 0)
                return totalSum;
    
            return totalSum - minNum;
        }
    };