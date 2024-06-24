#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<bool> isUpdated(n, false);
        int total = 0;
        int flips = 0;
        
        for(int i=0; i<n; i++){
            // Flips needed on current 
            if(i - k >= 0)
                flips -= isUpdated[i-k];

            // Current state of bit
            int curr = (nums[i] + flips) % 2;
            if(curr == 0){
                // Not possible 
                if(n - i < k)  return -1;

                flips++;
                total++;
                isUpdated[i] = true;
            }
        }

        return total;
    }
};