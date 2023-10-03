#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int numIdenticalPairs(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int total = 0;
        int freq[101] = {0};

        for(int i=0; i<n; i++){

            freq[nums[i]]++;
        }

        for(int i=1; i<101; i++){

            if(freq[i] != 0){

                int val = (freq[i] * (freq[i]-1)) / 2;
                total += val;
            }
        }

        return total;
    }
};