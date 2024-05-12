#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // We see atleast one person will be paid the same amount as wage[i]
    // double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
    //     int n = wage.size();

    //     double result = INT_MAX;

    //     for(int i=0; i<n; i++){

    //         priority_queue <double> pq;
    //         for(int j=0; j<n; j++){

    //             double cost = (wage[i] * (1.0) * quality[j]) / quality[i];
    //             if(cost >= wage[j])
    //                 pq.push(cost);

    //             if(pq.size() > k)
    //                 pq.pop();
    //         }


    //         if(pq.size() != k)
    //             continue;

    //         double total = 0;
    //         while(!pq.empty()){
    //             total += pq.top();
    //             pq.pop();
    //         }

    //         result = min(result, total);
    //     }

    //     return result;
    // }

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = wage.size();

        vector<pair<double, int>> ratio;
        for(int i=0; i<n; i++){

            double rate = (wage[i] * 1.0) / quality[i];
            ratio.push_back({rate, quality[i]});
        }

        sort(ratio.begin(), ratio.end());

        double result = INT_MAX;
        double total = 0;

        priority_queue<int> pq;
        for(int i=0; i<n; i++){

            pq.push(ratio[i].second);
            total += ratio[i].second;
        
            if(pq.size() > k){
                total -= pq.top();
                pq.pop();
            }

            // Only if we have k workers
            if(pq.size() == k){
                double amount = (total * ratio[i].first);
                result = min(amount, result);
            }
        }

        return result;
    }
};