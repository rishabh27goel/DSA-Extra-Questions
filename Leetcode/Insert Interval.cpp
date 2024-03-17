#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = intervals.size();

    //     // Insert the interval
    //     intervals.push_back(newInterval);
    //     sort(intervals.begin(), intervals.end());

    //     vector<vector<int>> result;
    //     int start = intervals[0][0];
    //     int end = intervals[0][1];

    //     for(int i=1; i<n+1; i++){
    //         // Overlap
    //         if(intervals[i][0] <= end) {
    //             end = max(end, intervals[i][1]);
    //         }
    //         else {
    //             result.push_back({start, end});
    //             start = intervals[i][0];
    //             end = intervals[i][1];
    //         }
    //     }

    //     result.push_back({start , end});
    //     return result;
    // }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = intervals.size();

        if(n == 0)
            return {newInterval};

        // Insert the interval
        int idx = n;

        int i = 0;
        int j = n-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(intervals[mid][0] <= newInterval[0]){
                i = mid + 1;
            }
            else {
                idx = mid;
                j = mid - 1;
            }
        }

        intervals.insert(intervals.begin() + idx, newInterval);

        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i<n+1; i++){
            // Overlap
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        result.push_back({start , end});
        return result;
    }
};