#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = names.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int &x, int &y){
            return heights[x] > heights[y];
        });

        vector<string> sortedNames;
        for(int i=0; i<n; i++){
            sortedNames.push_back(names[idx[i]]);
        }

        return sortedNames;
    }
};