#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int maxFreq = 0;
        int freq[101];

        memset(freq, 0, sizeof(freq));
    
        for(int i=0; i<n; i++){
            maxFreq = max(maxFreq, ++freq[nums[i]]);
        }

        int result = 0;

        for(int i=0; i<n; i++){
            if(freq[nums[i]] == maxFreq)
                result++;
        }

        return result;
    }
};