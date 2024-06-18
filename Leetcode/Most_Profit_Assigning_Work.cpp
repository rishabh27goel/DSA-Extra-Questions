#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = difficulty.size();
        int m = worker.size();

        int maxNum = *max_element(worker.begin(), worker.end());
        vector<int> jobs(maxNum + 1, 0);

        for(int i=0; i<n; i++){
            if(difficulty[i] <= maxNum)
                jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
        }

        int prefix = 0;
        for(int j=0; j<=maxNum; j++){
            prefix = max(prefix, jobs[j]);
            jobs[j] = prefix;
        }

        int total = 0;
        for(int i=0; i<m; i++){
            total += jobs[worker[i]];
        }

        return total;
    }

    // int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = difficulty.size();
    //     int m = worker.size();

    //     vector<pair<int, int>> job;
    //     for(int i=0; i<n; i++){
    //         job.push_back(make_pair(difficulty[i], profit[i]));
    //     }

    //     // Time : O(n * logn + m * logm)
    //     sort(job.begin(), job.end());
    //     sort(worker.begin(), worker.end());
    
    //     int totalProfit = 0;
    //     int maxProfit = 0;

    //     // Time : O(n + m)
    //     int i = 0;
    //     int j = 0;

    //     while(j < m){
    //         while(i < n && job[i].first <= worker[j]){
    //             maxProfit = max(maxProfit, job[i].second);
    //             i++;
    //         }
    //         totalProfit += maxProfit;
    //         j++;
    //     }

    //     return totalProfit;
    // }
};