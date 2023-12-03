#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = points.size();

        int result = 0;

        for(int i=1; i<n; i++){

            int absX = abs(points[i][0] - points[i-1][0]);
            int absY = abs(points[i][1] - points[i-1][1]);
        
            result += (min(absX, absY) + abs(absX - absY));
        }

        return result;
    }
};