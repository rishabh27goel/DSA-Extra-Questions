#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isValid(int n, vector<int> &nums, int val, int p){

        int c = 0;
        int i = 0;

        while(i < n-1){

            if(nums[i+1] - nums[i] <= val){

                i++;
                c++;

                if(c >= p)
                    return true;
            }

            i++;
        }

        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(p == 0)
            return 0;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = 0;
        int start = 0;
        int end = (nums[n-1] - nums[0]);
    
        while(start <= end){

            int mid = start + (end - start) / 2;

            if(isValid(n, nums, mid, p)){

                result = mid;
                end = mid - 1;
            }
            else{

                start = mid + 1;
            }
        }

        return result;
    }
};