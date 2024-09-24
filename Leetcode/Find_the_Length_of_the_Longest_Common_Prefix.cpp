#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // The trick was to pair using the prefix set 
    // Directly pairing with arr1 will give TLE
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        unordered_set<int> prefixSet;
        for(int j = 0; j < arr1.size(); j++) {
            int number = arr1[j];

            while(number > 0) {
                prefixSet.insert(number);
                number /= 10;
            }
        }

        int maxLength = 0;
        for(int j = 0; j < arr2.size(); j++) {
            int number = arr2[j];
            int len = 0;
            int find = -1;

            while(number > 0) {
                if(prefixSet.find(number) != prefixSet.end()) {
                    if(find == -1)  find = len;
                }
                
                len++;
                number /= 10;
            }

            if(find != -1)
                maxLength = max(maxLength, len - find);
        }

        return maxLength;
    }
};