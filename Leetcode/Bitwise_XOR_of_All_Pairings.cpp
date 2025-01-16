#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums1.size();
        int m = nums2.size();

        int xorOne = 0;
        for(int j = 0; j < n; j++) {
            xorOne ^= nums1[j];
        }

        int xorTwo = 0;
        for(int j = 0; j < m; j++) {
            xorTwo ^= nums2[j];
        }

        if(n % 2 == 0 && m % 2 == 0)
            return 0;

        else if(n % 2 == 0)
            return xorOne;  

        else if(m % 2 == 0)
            return xorTwo;

        return xorOne ^ xorTwo;
    }
};