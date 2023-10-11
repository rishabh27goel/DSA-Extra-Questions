#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int unique = 0;

        for(int i=0; i<n; i++){

            if(i+1 < n && nums[i] == nums[i+1])
                continue;

            nums[unique++] = nums[i];
        }


        int result = n;
        int j = 0;

        for(int i=0; i<unique; i++){

            int c = 1;

            while(j < unique && nums[j] < nums[i] + n){

                j++;
            }

            result = min(result, n - (j - i));
        }

        return result;
    }
};