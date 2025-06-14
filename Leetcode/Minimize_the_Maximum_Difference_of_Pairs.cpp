#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool validMaxValue(int size, vector<int> &nums, int pairs, int maxValue) {
            int currIdx = 0;
            int count = 0;
    
            while(currIdx + 1 < size) {
                if(nums[currIdx + 1] - nums[currIdx] <= maxValue) {
                    currIdx++;
                    pairs--;
    
                    if(pairs <= 0)
                        return true;
                }
                currIdx++;
            }
    
            return false;
        }
    
        int minimizeMax(vector<int>& nums, int p) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = nums.size();
    
            if(p == 0)  return 0;
    
            // Sort the array 
            sort(nums.begin(), nums.end());
    
            int minValue = INT_MAX;
            int leftMax = 0;
            int rightMax = nums[size - 1] - nums[0];
    
            while(leftMax <= rightMax) {
                int middleMax = leftMax + (rightMax - leftMax) / 2;
    
                if(validMaxValue(size, nums, p, middleMax)) {
                    minValue = middleMax;
                    rightMax = middleMax - 1;
                }
                else {
                    leftMax = middleMax + 1;
                }
            }
    
            return minValue;
        }
    };