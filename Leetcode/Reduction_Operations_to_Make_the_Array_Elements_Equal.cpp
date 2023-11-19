#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int freq[50001];

    int reductionOperations(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        for(int i=0; i<n; i++){

            freq[nums[i]]++;
        }

        int result = 0;

        int mul = 0;
        int j = 0;
    
        while(j < 50001){

            if(freq[j] != 0){

                result += (freq[j] * mul);
                mul++;
            }

            j++;
        }

        return result;
    }

    // int reductionOperations(vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     sort(nums.begin(), nums.end());

    //     int result = 0;
        
    //     int mul = 0;
    //     int j = 0;
    
    //     while(j < n){

    //         int val = nums[j];
    //         int c = 0; 

    //         while(j < n && nums[j] == val){

    //             c++;
    //             j++;
    //         }

    //         result += (c * mul);
    //         mul++;
    //     }

    //     return result;
    // }
};