#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int findPivotIndex(int n, vector<int> &nums){

        if(n == 1 || nums[0] < nums[n-1])
            return 0;

        int i = 0;
        int j = n-1;

        while(i < j){

            int mid = i + (j - i) / 2;

            if(nums[0] <= nums[mid]){

                i = mid + 1;
            }
            else{

                j = mid;
            }
        }

        return i;
    }

    int binarySearch(int n, vector<int> &nums, int start, int end, int target){

        if(start > end)
            return -1;


        while(start <= end){

            int mid = start + (end - start) / 2;

            if(nums[mid] == target){

                return mid;
            }
            else if(nums[mid] > target){

                end = mid - 1;
            }
            else{

                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size(); 

        int pivot = findPivotIndex(n, nums);

        if(nums[pivot] <= target && target <= nums[n-1]){

            return binarySearch(n, nums, pivot, n-1, target);
        }
        else{

            return binarySearch(n, nums, 0, pivot-1, target);
        }
    }
};