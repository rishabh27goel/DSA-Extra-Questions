#include <iostream>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long total = 0;

        int mid = (target / 2);
        int c = 0;

        for(int i=1; i<=mid && c < n; i++, c++){

            total += i;
        }

        for(int i=target; c < n; i++, c++){

            total += i;
        }

        return total;
    }
};
