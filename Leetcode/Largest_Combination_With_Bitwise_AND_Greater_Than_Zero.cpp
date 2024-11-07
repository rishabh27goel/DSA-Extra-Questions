#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = candidates.size();
        int bits[32] = {0};

        int maxLength = 0;
        for(int i = 0; i < n; i++) {
            int num = candidates[i];
            int j = 0;

            while(num > 0) {
                if(num & 1) {
                    maxLength = max(maxLength, ++bits[j]);
                }
                     
                j++; 
                num >>= 1;
            }
        }   

        return maxLength;
    }
};