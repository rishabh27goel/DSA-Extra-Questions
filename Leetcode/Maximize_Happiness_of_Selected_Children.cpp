#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), greater<int> ());

        long long result = 0;
        int c = 0;

        for(int i=0; i<k; i++){
            result += max(happiness[i] - c, 0);
            c++;
        }

        return result;
    }
};