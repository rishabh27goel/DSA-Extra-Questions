#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subSteps(long n, long start, long end) {
        int steps = 0;
        while(start <= n) {
            steps += (min(n + 1, end) - start);

            start *= 10;
            end *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int counter = 1;
        k--;

        while(k > 0) {
            int steps = subSteps(n, counter, counter + 1);
            if(steps <= k) {
                counter++;
                k -= steps;
            }
            else {
                counter *= 10;
                k--;
            }
        }

        return counter;
    }
};