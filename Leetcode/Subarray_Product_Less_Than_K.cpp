#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int total = 0;
        int product = 1;

        int i = 0;
        int j = 0;

        while(j < n){

            product *= nums[j];
            while(i <= j && product >= k){
                
                product /= nums[i];
                i++;
            }

            total += (j - i + 1);
            j++;
        }

        return total;
    }
};