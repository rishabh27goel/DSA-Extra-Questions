#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // First thought of dp
    // Not possible because of the constraints

    int minOperations(vector<int>& nums, int x) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int sum = 0;

        for(int i=0; i<n; i++){

            sum += nums[i];
        }

        if(sum == x)
            return n;

        if(sum < x)
            return -1;


        int result = n;
        int target = sum - x;
        int prefix = 0;

        int i = 0;
        int j = 0;
        

        while(j < n){

            prefix += nums[j];

            while(i <= j && prefix > target){

                prefix -= nums[i];
                i++;
            }

            if(prefix == target)
                result = min(n - (j - i + 1), result);

            j++;
        }

        return result == n ? -1 : result;
    }
};