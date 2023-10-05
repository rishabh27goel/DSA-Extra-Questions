#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    long long findMaxSum(int n, vector<int> &maxHeights, int idx){

        long long total = maxHeights[idx];
        
        int prev = maxHeights[idx];

        for(int i=idx-1; i>=0; i--){

            prev = min(maxHeights[i], prev);
            total += prev;
        }

        prev = maxHeights[idx];

        for(int i=idx+1; i<n; i++){

            prev = min(maxHeights[i], prev);
            total += prev;
        }

        return total;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = maxHeights.size();

        long long maxTotal = 0; 

        for(int i=0; i<n; i++){

            long long total = findMaxSum(n, maxHeights, i);
        
            maxTotal = max(total, maxTotal);
        }

        return maxTotal;
    }
};