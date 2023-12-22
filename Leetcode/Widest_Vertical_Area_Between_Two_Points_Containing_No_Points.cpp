#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = points.size();

        // Sort the points
        sort(points.begin(), points.end());


        int maxWidth = 0;

        for(int i=1; i<n; i++){

            maxWidth = max(abs(points[i][0] - points[i-1][0]), maxWidth);
        }

        return maxWidth;
    }
};