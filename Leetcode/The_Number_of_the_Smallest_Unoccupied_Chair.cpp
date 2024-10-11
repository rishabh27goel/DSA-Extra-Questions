#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = times.size();

        priority_queue<int, vector<int>, greater<int>> freeChair; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minTime;

        for(int j = 0; j < n; j++) {
            times[j].push_back(j);
            freeChair.push(j);
        }

        // Sort by arrival time
        sort(times.begin(), times.end());

        for(int j = 0; j < n; j++) {
            int start = times[j][0];
            int end = times[j][1];
            int idx = times[j][2];

            while(!minTime.empty() && minTime.top().first <= start) {
                freeChair.push(minTime.top().second);
                minTime.pop();
            }

            int chair = freeChair.top();
            freeChair.pop();

            if(idx == targetFriend)
                return chair;

            minTime.push(make_pair(end, chair));
        }

        return -1;
    }
};