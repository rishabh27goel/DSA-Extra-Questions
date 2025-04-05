#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int subsetXORSum(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int size = nums.size();

    //     int power = pow(2, size);
    //     int totalSum = 0;

    //     for(int mask = 0; mask < power; mask++) {
    //         int currXor = 0;
    //         for(int bit = 0; bit < size; bit++) {
    //             if(mask & (1 << bit))
    //                 currXor ^= nums[bit];
    //         }
    //         totalSum += currXor;
    //     }

    //     return totalSum;
    // }

    int subsetXORSum(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        int orTotal = 0;

        for(int i=0; i<n; i++){
            orTotal |= nums[i];
        }

        return orTotal << (n - 1);
    }
};