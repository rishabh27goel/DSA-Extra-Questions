#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = pref.size();

        int prefix = 0;

        for(int i=0; i<n; i++){

            pref[i] = pref[i] ^ prefix;
            prefix ^= pref[i];
        }

        return pref;
    }
};