#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int j = 0;

        while(j < n){
            if(nums[j] > 0 && nums[j] <= n && nums[j] != nums[nums[j]-1]) {
                swap(nums[j], nums[nums[j]-1]);
            }
            else {
                j++;
            }
        }

        int smallest = 1;

        for(int i=0; i<n; i++){
            if(nums[i] != i+1)
                return i + 1;
        }

        return n + 1;
    }
};