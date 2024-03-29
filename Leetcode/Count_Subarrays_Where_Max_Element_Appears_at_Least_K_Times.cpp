#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int maxNum = 0;
        
        for(int i=0; i<n; i++){    
            maxNum = max(maxNum, nums[i]);
        }

        long long total = 0;
        int c = 0;

        int i = 0;
        int j = 0;

        while(j < n){

            c += (maxNum == nums[j]);

            while(i <= j && c > k-1){
                c -= (maxNum == nums[i]);
                i++;
            }

            total += (j - i + 1);
            j++;
        }

        long long result = (((long long) n * (n + 1)) / 2);
        return result - total;
    }
};