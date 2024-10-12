#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minTime;
        int maxGroups = 0;

        for(int j = 0; j < n; j++) {
            int start = intervals[j][0];
            int end = intervals[j][1];

            if(minTime.empty() || minTime.top() >= start) {
                minTime.push(end);
            }
            else {
                minTime.pop();
                minTime.push(end);
            }

            maxGroups = max(maxGroups, (int) minTime.size());
        }

        return maxGroups;
    }

    // int minGroups(vector<vector<int>>& intervals) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = intervals.size();

    //     map<int, int> points;
    //     for(int j = 0; j < intervals.size(); j++) {
    //         int start = intervals[j][0];
    //         int end = intervals[j][1];

    //         points[start]++;
    //         points[end + 1]--;
    //     }

    //     int maxGroups = 0;
    //     int groups = 0;

    //     for(auto mpItr : points) {
    //         groups += mpItr.second;
    //         maxGroups = max(maxGroups, groups);
    //     }

    //     return maxGroups;
    // }

    // int minGroups(vector<vector<int>>& intervals) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = intervals.size();

    //     int minStart = INT_MAX;
    //     int maxEnd = INT_MIN;
    //     for(int j = 0; j < intervals.size(); j++) {
    //         int start = intervals[j][0];
    //         int end = intervals[j][1];

    //         minStart = min(start, minStart);
    //         maxEnd = max(end, maxEnd);
    //     }

    //     vector<int> groupsTrack(maxEnd + 5, 0);
    //     for(int j = 0; j < intervals.size(); j++) {
    //         int start = intervals[j][0];
    //         int end = intervals[j][1];

    //         groupsTrack[start]++;
    //         groupsTrack[end + 1]--;
    //     }

    //     int maxGroups = 0;
    //     int groups = 0;

    //     for(int j = minStart; j <= maxEnd; j++) {
    //         groups += groupsTrack[j];
    //         maxGroups = max(maxGroups, groups);
    //     }

    //     return maxGroups;
    // }
};