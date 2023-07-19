#include <iostream>
using namespace std;

// Method 1 : 
// Time : O(n * log(n))  Space : O(n) 
// int maximumActivities(vector<int> &startArr, vector<int> &finishArr) {
    
//     int n = startArr.size();

//     vector<vector<int>> intervals;

//     for(int i=0; i<n; i++){

//         intervals.push_back({startArr[i], finishArr[i]});
//     }

//     sort(intervals.begin(), intervals.end(), [&](const vector<int> &v1, const vector<int> &v2){

//         if(v1[1] == v2[1])
//             return v1[0] < v2[0];

//         return v1[1] < v2[1];
//     });


//     int result = 1;
//     int start = intervals[0][0];
//     int end = intervals[0][1];

//     for(int i=1; i<n; i++){

//         if(intervals[i][0] >= end){

//             result++;
//             start = intervals[i][0];
//             end = intervals[i][1];
//         }
//     }

//     return result;
// }

// Method 2 : 
// Time : O(n * log(n))  Space : O(n) 
int maximumActivities(vector<int> &startArr, vector<int> &finishArr) {
    
    int n = startArr.size();

    vector<vector<int>> intervals;

    for(int i=0; i<n; i++){

        intervals.push_back({startArr[i], finishArr[i]});
    }

    sort(intervals.begin(), intervals.end(), [&](const vector<int> &v1, const vector<int> &v2){

        if(v1[0] == v2[0])
            return v1[1] < v2[1];

        return v1[0] < v2[0];
    });


    int result = 1;
    int start = intervals[0][0];
    int end = intervals[0][1];

    for(int i=1; i<n; i++){

        if(intervals[i][0] < end){

            end = min(intervals[i][1], end);
        }
        else{

            result++;
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    return result;
}