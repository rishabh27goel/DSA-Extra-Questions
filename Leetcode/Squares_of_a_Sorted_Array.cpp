#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<int> sortedSquares(vector<int>& nums) {
        
    //     int n = nums.size();

    //     vector<int> result;

    //     for(int i=0; i<n; i++){
    //         result.push_back(nums[i] * nums[i]);
    //     }

    //     sort(result.begin(), result.end());

    //     return result;
    // }

    vector<int> sortedSquares(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> result(n);

        int idx = n-1;
        int i = 0;
        int j = n-1;

        while(idx >= 0){
            
            if(nums[i] * nums[i] > nums[j] * nums[j]){
                result[idx] = nums[i] * nums[i];
                i++;
            }
            else {
                result[idx] = nums[j] * nums[j];
                j--;
            }

            idx--;
        }

        return result;
    }
};