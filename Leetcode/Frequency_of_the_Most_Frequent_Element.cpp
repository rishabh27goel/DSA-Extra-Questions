#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        int result = 0;
        long total = 0;
        int i = 0;
        int j = 0;

        while(j < n){

            total += nums[j];

            while(i <= j && ((long) nums[j] * (j - i + 1)) > total + k){

                total -= nums[i];
                i++;
            }

            result = max((j - i + 1), result);
            j++;
        }

        return result;
    }

    // int maxFrequency(vector<int>& nums, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     // Sort the array
    //     sort(nums.begin(), nums.end());


    //     vector<long> prefix(n, 0);
    //     vector<long> preprefix(n, 0);
    
    //     long prefixSum = 0;
    //     long preprefixSum = 0;

    //     for(int i=n-2; i>=0; i--){

    //         prefixSum += (nums[i+1] - nums[i]);
    //         preprefixSum += prefixSum;

    //         prefix[i] = prefixSum;
    //         preprefix[i] = preprefixSum;
    //     }
    
    //     int result = 0;
    //     int i = 0;
    //     int j = 0;

    //     while(j < n && i <= j){

    //         long windowSum = (preprefix[i] - preprefix[j]) - ((j - i) * prefix[j]);

    //         if(windowSum <= (long) k){
    //             result = max(j - i + 1, result);
    //             j++;
    //         }
    //         else {
    //             i++;
    //         }
    //     }

    //     return result;
    // }
};