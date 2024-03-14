#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     int result = 0;
    //     int total = 0;
    //     unordered_map<int, int> mp;
    //     mp[0] = 1;

    //     for(int i=0; i<n; i++){
    //         total += nums[i];
    //         result += mp[total-goal];
    //         mp[total]++;
    //     }

    //     return result;
    // }

    int findMostCount(vector<int> &nums, int goal){

        int n = nums.size();

        int result = 0;
        int total = 0;

        int i = 0;
        int j = 0;

        while(j < n){

            total += nums[j];
            while(i <= j && total > goal){

                total -= nums[i];
                i++;
            }

            result -= (j - i + 1);
            j++;
        }

        return result;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        return findMostCount(nums, goal-1) - findMostCount(nums, goal);
    }
};