#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Two Iteration
    // int findAtMostK(int n, vector<int> &nums, int k) {

    //     int total = 0;
    //     int odd = 0;
        
    //     int i = 0;
    //     int j = 0;

    //     while(j < n){
    //         odd += (nums[j] % 2);

    //         while(i <= j && odd > k){
    //             odd -= (nums[i] % 2);
    //             i++;
    //         }

    //         total += (j - i + 1);
    //         j++;
    //     }

    //     return total;
    // }

    // int numberOfSubarrays(vector<int>& nums, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     return findAtMostK(n, nums, k) - findAtMostK(n, nums, k-1);
    // }

    // Single Iteration
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int result = 0;
        int odd = 0;
        int subCount = 0;

        int i = 0;
        int j = 0;

        while(j < n){
            if(nums[j] & 1){
                odd++;
                if(odd >= k){
                    subCount = 1;
                    while(nums[i++] % 2 != 1){
                        subCount++;
                    }
                }
            }

            if(odd >= k)  result += subCount;
            j++; 
        }

        return result;
    }
};