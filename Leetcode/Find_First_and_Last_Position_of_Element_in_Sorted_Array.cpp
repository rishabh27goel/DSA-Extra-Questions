#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int lowerBound(vector<int> &nums, int target){

        int n = nums.size();

        int idx = -1;
        int i = 0;
        int j = n-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(nums[mid] == target){

                idx = mid;
                j = mid-1;
            }
            else if(nums[mid] > target){

                j = mid-1;
            }
            else{

                i = mid+1;
            }
        }

        return idx;
    }

    int upperBound(vector<int> &nums, int target){

        int n = nums.size();

        int idx = -1;
        int i = 0;
        int j = n-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(nums[mid] == target){

                idx = mid;
                i = mid+1;
            }
            else if(nums[mid] > target){

                j = mid-1;
            }
            else{

                i = mid+1;
            }
        }

        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        return { lowerBound(nums, target) , upperBound(nums, target) };
    }
};