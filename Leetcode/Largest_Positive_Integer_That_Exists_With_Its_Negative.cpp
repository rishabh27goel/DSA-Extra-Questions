#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int largest = -1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0 && st.find(-nums[i]) != st.end())
                largest = max(largest, nums[i]);
        }

        return largest;
    }
};