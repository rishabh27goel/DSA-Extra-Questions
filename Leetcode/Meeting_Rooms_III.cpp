#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        // To track the meeting end time (when we can start the next meeting)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> meetingEndTracker;

        // To get the least free room 
        priority_queue<int, vector<int>, greater<int>> leastFreeRoom;

        // Track the number of times room used
        int roomFreq[n];
        memset(roomFreq, 0, sizeof(roomFreq));


        // All the rooms are free at start
        for(int i=0; i<n; i++){
            leastFreeRoom.push(i);
        }

        for(int i=0; i<m; i++){

            long long start = meetings[i][0];
            long long end = meetings[i][1];

            while(!meetingEndTracker.empty() && meetingEndTracker.top().first <= start){

                leastFreeRoom.push(meetingEndTracker.top().second);
                meetingEndTracker.pop();
            }

            // No free rooms is there
            if(leastFreeRoom.empty()){

                pair<long long, int> smallestEndtime = meetingEndTracker.top();
                meetingEndTracker.pop();

                roomFreq[smallestEndtime.second] += 1;

                long long diff = end - start;
                meetingEndTracker.push(make_pair(smallestEndtime.first + diff, smallestEndtime.second));
            }
            else {

                int room = leastFreeRoom.top();
                leastFreeRoom.pop();

                roomFreq[room] += 1;

                meetingEndTracker.push(make_pair((long) end, room));
            }
        }

        int maxFreq = 0;

        for(int i=1; i<n; i++){
            if(roomFreq[maxFreq] < roomFreq[i]){
                maxFreq = i;
            }
        }

        return maxFreq;
    }
};