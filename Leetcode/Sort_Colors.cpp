#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int i = 0;
        int j = 0;
        int k = n-1;

        while(j <= k){
            if(nums[j] == 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if(nums[j] == 1){
                j++;
            }
            else {
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};