#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;
        int counter = 1;
        int j = 0;

        while(j < sorted.size()) {
            int val = sorted[j];
            while(j < sorted.size() && val == sorted[j]) {
                j++;
            }

            mp[val] = counter++;
        }

        for(int j = 0; j < arr.size(); j++) {
            arr[j] = mp[arr[j]];
        }

        return arr;
    }
};