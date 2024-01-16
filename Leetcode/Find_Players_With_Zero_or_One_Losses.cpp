#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = matches.size();

        unordered_map<int, pair<int, int>> losers;

        for(int i=0; i<n; i++){

            losers[matches[i][0]].first++;
            losers[matches[i][1]].second++;
        }

        vector<int> win;
        vector<int> loss;

        for(auto itr = losers.begin(); itr != losers.end(); itr++){

            if(itr->second.second == 0){
                win.push_back(itr->first);
            }
            else if(itr->second.second == 1){
                loss.push_back(itr->first);
            }
        }

        sort(win.begin(), win.end());
        sort(loss.begin(), loss.end());

        return {win, loss};
    }
};