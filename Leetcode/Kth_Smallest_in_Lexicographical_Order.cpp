#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int getSteps(long n, long start, long end) {
            int steps = 0;
            while(start <= n) {
                steps += (min(n + 1, end) - start);
                start *= 10;
                end *= 10;
            }
            return steps;
        }
    
        int findKthNumber(int n, int k) {
            int counter = 1;
            k--;
    
            while(k > 0) {
                int steps = getSteps(n, counter, counter + 1);
                if(steps <= k) {
                    k -= steps;
                    counter++;
                }
                else {
                    k--;
                    counter *= 10;
                }
            }
    
            return counter;
        }
    };