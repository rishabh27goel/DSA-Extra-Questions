#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end(), [&](int &x, int &y){
            string strX = to_string(x);
            string strY = to_string(y);

            return strX + strY > strY + strX; 
        });

        // Edge Case
        if(nums[0] == 0)
            return "0";

        string number = "";
        for(int j = 0; j < nums.size(); j++) {
            number += to_string(nums[j]);
        }
        return number;
    }
};