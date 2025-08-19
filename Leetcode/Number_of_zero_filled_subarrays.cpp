#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = nums.size();
    
            long long totalSubs = 0;
            int currIdx = 0;
    
            while(currIdx < size) {
                if(nums[currIdx] != 0) {
                    currIdx++;
                }
                else {
                    int count = 1;
                    while(currIdx < size && nums[currIdx] == 0) {
                        totalSubs += count;
                        count++, currIdx++;
                    }
                }
            }
            return totalSubs;
        }
    };