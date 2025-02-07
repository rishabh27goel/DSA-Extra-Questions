#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = queries.size();

        vector<int> distinct;
        unordered_map<int, int> queryHistory;
        unordered_map<int, int> colorCount;

        for(int queryIdx = 0; queryIdx < n; queryIdx++) {
            int ball = queries[queryIdx][0];
            int color = queries[queryIdx][1];

            auto historyItr = queryHistory.find(ball);
            if(historyItr != queryHistory.end()) {
                int currColor = historyItr->second;
                if(--colorCount[currColor] == 0)
                    colorCount.erase(currColor);
            }

            queryHistory[ball] = color;
            colorCount[color]++;
            distinct.push_back(colorCount.size());
        }

        return distinct;
    }
};