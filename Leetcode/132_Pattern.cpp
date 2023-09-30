#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        int thirdNum = INT_MIN;
        stack<int> decNum;

        for(int i=n-1; i>=0; i--){

            // If Third Number is assigned [Check for 132 pattern]
            if(thirdNum > nums[i])
                return true;

            while(!decNum.empty() && decNum.top() < nums[i]){

                thirdNum = decNum.top();
                decNum.pop();
            }

            decNum.push(nums[i]);
        }

        return false;
    }
};