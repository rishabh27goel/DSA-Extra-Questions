#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        priority_queue<pair<double, pair<int, int>>> pq;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double fraction = (arr[i] * 1.0) / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});

                if(pq.size() > k)
                    pq.pop();
            }
        }

        pair<int, int> pr = pq.top().second;
        return {pr.first, pr.second};
    }
};