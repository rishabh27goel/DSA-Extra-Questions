#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int i = 0;
        int j = n-1;

        while(i < j){

            if(nums[i] % 2 == 0){

                i++;
            }
            else {

                swap(nums[i], nums[j]);
                j--;
            }
        }

        return nums;
    }
};