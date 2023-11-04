#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int lastMoment = 0;

        for(int i=0; i<left.size(); i++){

            lastMoment = max(lastMoment, left[i]);
        }

        for(int i=0; i<right.size(); i++){

            lastMoment = max(lastMoment, n - right[i]);
        }

        return lastMoment;
    }
};