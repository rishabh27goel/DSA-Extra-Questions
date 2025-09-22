#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxFrequencyElements(vector<int>& nums) {
            int freq[101] = {0};
            int totalFreq = 0;
            int maxFreq = 0;
    
            for(int idx = 0; idx < nums.size(); idx++) {
                freq[nums[idx]]++;
                if(maxFreq < freq[nums[idx]]) {
                    maxFreq = freq[nums[idx]];
                    totalFreq = maxFreq;
                }
                else if(maxFreq == freq[nums[idx]]) {
                    totalFreq += maxFreq;
                }
            }
            return totalFreq;
        }
    };