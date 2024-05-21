#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int subsetXORSum(vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     int result = 0;
    //     int p = pow(2, n);

    //     for(int i=0; i<p; i++){

    //         int total = 0;

    //         for(int j=0; j<n; j++){
    //             if((i & (1 << j)))  
    //                 total ^= nums[j];
    //         }

    //         result += total;
    //     }

    //     return result;
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