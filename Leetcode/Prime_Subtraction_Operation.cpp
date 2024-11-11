#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prime;
    bool sieve[1005];
    
    void fillSieve() {
        memset(sieve, true, sizeof(sieve));

        sieve[0] = false;
        sieve[1] = false;

        for(int i = 2; i * i < 1005; i++) {
            if(sieve[i]) {
                for(int j = i * i; j < 1005; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    int findLowerBound(int target) {
        if(target < 0)
            return 0;

        int candidate = 0;
        int start = 0;
        int end = prime.size()-1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(prime[mid] < target) {
                candidate = prime[mid];
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return candidate;
    }

    bool primeSubOperation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        fillSieve();
        for(int j = 0; j < 1005; j++) {
            if(sieve[j])
                prime.push_back(j);
        }

        int prevNum = 0;
        for(int j = 0; j < nums.size(); j++) {
            int lower = findLowerBound(nums[j] - prevNum);
            if(nums[j] - lower <= prevNum)
                return false;

            prevNum = nums[j] - lower;
        }

        return true;
    }
};