#include <iostream>
#include <vector>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> overlap;
    vector<pair<int, int>> nonOverlap;

    MyCalendarTwo() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    bool book(int start, int end) {
        // Check in overlapping intervals
        for(auto interval : overlap) {
            if(end > interval.first && interval.second > start)
                return false;
        }

        // Check in non-overlapping intervals
        for(auto interval : nonOverlap) {
            if(end > interval.first && interval.second > start) {
                overlap.push_back(make_pair(max(start, interval.first), min(end, interval.second)));
            }   
        }

        nonOverlap.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// class MyCalendarTwo {
// public:
//     map<int, int> points;

//     MyCalendarTwo() {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//     }
    
//     bool book(int start, int end) {
//         // Add the interval
//         points[start]++;
//         points[end]--;

//         int events = 0;
//         for(auto pr : points) {
//             events += pr.second;

//             if(events > 2) {
//                 points[start]--;
//                 points[end]++;

//                 if(points[start] == 0)
//                     points.erase(start);

//                 if(points[end] == 0)
//                     points.erase(end);

//                 return false;
//             }
//         }

//         return true;
//     }
// };

// /**
//  * Your MyCalendarTwo object will be instantiated and called as such:
//  * MyCalendarTwo* obj = new MyCalendarTwo();
//  * bool param_1 = obj->book(start,end);
//  */

