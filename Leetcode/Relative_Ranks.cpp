#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();

        vector<pair<int, int>> mapping;
        for(int i=0; i<n; i++){
            mapping.push_back(make_pair(score[i], i));
        }

        sort(mapping.begin(), mapping.end(), greater<pair<int, int>> ());

        vector<string> result(n, "");
        for(int i=0; i<n; i++){

            int idx = mapping[i].second;
            
            if(i == 0)
                result[idx] = "Gold Medal";
            else if(i == 1)
                result[idx] = "Silver Medal";
            else if(i == 2)
                result[idx] = "Bronze Medal";
            else
                result[idx] = to_string(i + 1);
        }

        return result;
    }
};