#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findUpperBound(vector<int> &incArr, int target){

        int idx = -1;

        int i = 0;
        int j = incArr.size()-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(target <= incArr[mid]){

                idx = mid;
                j = mid - 1;
            }
            else {

                i = mid + 1;
            }
        }

        return idx;
    }

    int lengthOfLIS(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> arr;

        for(int i=0; i<n; i++){

            int idx = findUpperBound(arr, nums[i]);
            
            if(idx == -1){
                arr.push_back(nums[i]);
            }
            else {
                arr[idx] = nums[i];
            }
        }

        return arr.size();
    }
};