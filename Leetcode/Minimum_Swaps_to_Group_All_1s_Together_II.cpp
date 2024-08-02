#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
 
    // We know the total ones
    // So, we will try to find the subarray which has maximum 1's already present
    int minSwaps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int onesLength = 0;
        for(int i=0; i<n; i++){
            onesLength += nums[i];
        }

        if(onesLength <= 1)   return 0;

        int i = 0;
        int j = 0;
        int c = 0;

        int maxOnes = 0;
        int ones = 0;

        while(j < 2 * n){            
            ones += nums[j % n];
            c++;    

            if(c > onesLength){
                ones -= nums[i % n];
                i++ , c--;
            }

            maxOnes = max(ones, maxOnes);
            j++;
        }

        return onesLength - maxOnes;
    }
};