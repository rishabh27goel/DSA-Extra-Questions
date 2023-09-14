#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = ratings.size();

        vector<int> candyCount(n, 1);

        for(int i=0; i<n-1; i++){

            if(ratings[i] < ratings[i+1]){

                candyCount[i+1] = candyCount[i] + 1;
            }
        }

        int total = candyCount[n-1];

        for(int i=n-2; i>=0; i--){

            if(ratings[i] > ratings[i+1]){

                candyCount[i] = max(candyCount[i], candyCount[i+1] + 1);
            }

            total += candyCount[i];
        }

        return total;
    }
};