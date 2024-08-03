#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);
        
        int n = arr.size();

        int numCount[1001] = {0};
        for(int i=0; i<n; i++){
            numCount[arr[i]]++;
            numCount[target[i]]--;
        }

        for(int i=0; i<1001; i++){
            if(numCount[i] != 0)
                return false;
        }

        return true;
    }
};