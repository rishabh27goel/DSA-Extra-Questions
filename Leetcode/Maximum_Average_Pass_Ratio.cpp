#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // double findDifference(auto &pr) {
    //     double curr = (double) pr.first / pr.second;
    //     double next = (double) (pr.first + 1) / (pr.second + 1);
    //     return next - curr;
    // }

    // double maxAverageRatio(vector<vector<int>>& classes, int extra) {  
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = classes.size();

    //     auto customCompare = [&](auto &prX, auto &prY) {
    //         double diffX = findDifference(prX);
    //         double diffY = findDifference(prY);
    //         return diffX < diffY;
    //     };

    //     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(customCompare)> pq(customCompare);
    //     for(int j = 0; j < n; j++) {
    //         pq.push({classes[j][0], classes[j][1]});
    //     }

    //     while(extra--) {
    //         auto pr = pq.top();
    //         pq.pop();
    //         pq.push({pr.first + 1, pr.second + 1});
    //     }

    //     double totalAvg = 0;

    //     while(!pq.empty()) {
    //         auto pr = pq.top();
    //         pq.pop();
    //         totalAvg += (double) pr.first / pr.second;
    //     }

    //     return totalAvg / n;
    // }

    class CustomCompare {
        public:
            bool operator()(pair<int, int> &prX, pair<int, int> &prY) {
                double diffX = findDifference(prX);
                double diffY = findDifference(prY);
                return diffX < diffY;
            }

            double findDifference(pair<int, int> &pr) {
                double curr = (double) pr.first / pr.second;
                double next = (double) (pr.first + 1) / (pr.second + 1);
                return next - curr;
            }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extra) {  
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = classes.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;
        for(int j = 0; j < n; j++) {
            pq.push({classes[j][0], classes[j][1]});
        }

        while(extra--) {
            auto pr = pq.top();
            pq.pop();
            pq.push({pr.first + 1, pr.second + 1});
        }

        double totalAvg = 0;
        while(!pq.empty()) {
            auto pr = pq.top();
            pq.pop();
            totalAvg += (double) pr.first / pr.second;
        }

        return totalAvg / n;
    }
};