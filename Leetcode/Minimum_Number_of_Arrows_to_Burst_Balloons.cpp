#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = points.size();

        // Sort the points
        sort(points.begin(), points.end());

        int arrows = 1;
        int start = points[0][0];
        int end = points[0][1];

        for(int i=1; i<n; i++){
            if(end < points[i][0]) {
                start = points[i][0];
                end = points[i][1];
                arrows++;
            }
            else {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            }
        }   

        return arrows;
    }
};