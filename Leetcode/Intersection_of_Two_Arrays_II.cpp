#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n1; i++){
            mp[nums1[i]]++;
        }

        vector<int> result;
        for(int i=0; i<n2; i++){
            if(mp[nums2[i]] > 0){
                result.push_back(nums2[i]);
                mp[nums2[i]]--; 
            }
        }

        return result;
    }
};