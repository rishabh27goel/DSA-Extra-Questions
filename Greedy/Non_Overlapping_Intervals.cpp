#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Sort by End Time
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// static bool compare(pair<int, int> &p1, pair<int, int> &p2){

//     if(p1.second == p2.second)
//         return p1.first < p2.first;

//     return p1.second < p2.second;
// }

// int nonOverlappingInterval(vector< pair<int, int> > &interval){

//     int n = interval.size();

//     // Sort by End Interval
//     sort(interval.begin(), interval.end(), compare);

//     int result = 0;
//     pair<int, int> start = interval[0];

//     for(int i=1; i<n; i++){

//         // Valid Interval
//         if(start.second <= interval[i].first){

//             start = interval[i];
//         }
//         else{

//             result++;
//         }
//     }

//     return result;
// }

// Method 2 : Sort by Start Time
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
int nonOverlappingInterval(vector< pair<int, int> > &interval){

    int n = interval.size();

    // Sort by End Interval
    sort(interval.begin(), interval.end());

    int result = 0;
    int minEndTime = interval[0].second;

    for(int i=1; i<n; i++){

        if(interval[i].first < minEndTime){

            result++;
            minEndTime = min(interval[i].second, minEndTime);
        }
        else{

            minEndTime = interval[i].second;
        }
    }

    return result;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector< pair<int, int> > interval;

    for(int i=0; i<size; i++){

        int s, e;
        cin >> s >> e;

        interval.push_back(make_pair(s, e));
    }

    // Non Overlapping Interval
    int removal = nonOverlappingInterval(interval);

    cout << "Removal Required : " << removal;


    cout << endl;
    return 0;
}