#include <iostream>
#include <vector>
using namespace std;

#define SIZE 1000001
bool isPrime[SIZE];

class Solution {
public:
    Solution() { 
        fillPrimeNumbers(); 
    }

    void fillPrimeNumbers() {
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int num = 2; num * num < SIZE; num++) {
            if(isPrime[num]) {
                for(int mul = num * num; mul < SIZE; mul += num) {
                    isPrime[mul] = 0;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        if(left == right)
            return {-1, -1};

        int closestNumbers = INT_MAX;
        int closestStart = -1;

        int prevNum = -1;
        for(int currNum = left; currNum <= right; currNum++) {
            if(isPrime[currNum]) {
                if(prevNum != -1) {
                    int difference = currNum - prevNum;
                    if(closestNumbers > difference) {
                        closestNumbers = difference;
                        closestStart = prevNum;
                    }
                }
                prevNum = currNum;
            }
        }

        if(closestStart == -1)
            return {-1, -1};

        return {closestStart, closestStart + closestNumbers};
    }
};