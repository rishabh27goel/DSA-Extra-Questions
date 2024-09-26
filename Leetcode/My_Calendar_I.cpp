#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class MyCalendar {
// public:
//     vector<pair<int, int>> events;
//     MyCalendar() {}
    
//     bool book(int start, int end) {
//         bool valid = true;
//         for(int j = 0; j < events.size(); j++) {
//             int eS = events[j].first;
//             int eE = events[j].second;

//             if(!(end <= eS || start >= eE))
//                 valid = false;
//         }

//         if(!valid)
//             return false;

//         events.push_back(make_pair(start, end));
//         return true;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */

class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    bool book(int start, int end) {
        auto itr = events.upper_bound(start);

        if(itr != events.end() && itr->second < end)
            return false;

        events[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */