#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int maxNum1 = INT_MIN;
        int maxNum2 = INT_MIN;

        int maxIdx1 = -1;
        int maxIdx2 = -1;

        for(int i=0; i<n; i++){

            if(maxNum1 < nums[i]){

                maxNum2 = maxNum1;
                maxIdx2 = maxIdx1; 
                maxNum1 = nums[i];
                maxIdx1 = i;
            }
            else if(maxNum2 < nums[i]){

                maxNum2 = nums[i];
                maxIdx2 = i;
            }
        }

        int minNum1 = INT_MAX;
        int minNum2 = INT_MAX;

        for(int i=0; i<n; i++){

            if(maxIdx1 == i || maxIdx2 == i)
                continue;

            if(minNum1 > nums[i]){

                minNum2 = minNum1;
                minNum1 = nums[i];
            }
            else if(minNum2 > nums[i]){

                minNum2 = nums[i];
            }
        }

        return (maxNum1 * maxNum2) - (minNum1 * minNum2);
    }
};