#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = ratings.size();
    
            vector<int> candyCount(size, 1);
            for(int idx = 0; idx < size - 1; idx++) {
                if(ratings[idx] < ratings[idx + 1])
                    candyCount[idx + 1] = candyCount[idx] + 1;
            }
    
            for(int idx = size - 1; idx >= 1; idx--) {
                if(ratings[idx - 1] > ratings[idx])
                    candyCount[idx - 1] = max(candyCount[idx - 1], candyCount[idx] + 1);
            }
    
            return (int) accumulate(candyCount.begin(), candyCount.end(), 0);
        }
    };