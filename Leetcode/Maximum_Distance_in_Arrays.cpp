#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int maxDistance(vector<vector<int>>& arrays) { 
    //     int maxDistance = INT_MIN;
    //     for(int i = 0; i < arrays.size(); i++) {
    //         for(int j = 0; j < arrays.size(); j++){
    //             if(i != j) {
    //                 int size = arrays[j].size()-1;
    //                 maxDistance = max(maxDistance, abs(arrays[i][0] - arrays[j][size]));
    //             }
    //         }
    //     }
    //     return maxDistance;
    // }

    // int maxDistance(vector<vector<int>>& arrays) { 
    //     int size = arrays[0].size();
    //     long maxNum = arrays[0][size-1];
    //     long minNum = arrays[0][0];

    //     long maxDist = INT_MIN;
    //     for(int i=1; i<arrays.size(); i++){
    //         int m = arrays[i].size();
    //         maxDist = max(maxDist, abs(maxNum - arrays[i][0]));
    //         maxDist = max(maxDist, abs(arrays[i][m-1] - minNum));

    //         minNum = min(minNum, (long) arrays[i][0]);
    //         maxNum = max(maxNum, (long) arrays[i][m-1]);
    //     }

    //     return maxDist;
    // }

    int maxDistance(vector<vector<int>>& arrays) { 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int minNum = arrays[0].front();
        int maxNum = arrays[0].back();

        int maxDist = INT_MIN;
        for(int i=1; i<arrays.size(); i++) {
            auto &single = arrays[i];

            maxDist = max(maxDist, abs(maxNum - single.front()));
            maxDist = max(maxDist, abs(single.back() - minNum));

            minNum = min(minNum, single.front());
            maxNum = max(maxNum, single.back());
        }

        return maxDist;
    }
};
