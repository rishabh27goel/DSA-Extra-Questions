#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums1.size();
        int m = nums2.size();

        vector<int> result;

        int freq[1001];
        memset(freq, 0, sizeof(freq));

        for(int i=0; i<n; i++){
            freq[nums1[i]]++;
        }

        for(int i=0; i<m; i++){
            if(freq[nums2[i]] > 0){
                result.push_back(nums2[i]);
                freq[nums2[i]] = 0;
            }
        }

        return result;
    }
};