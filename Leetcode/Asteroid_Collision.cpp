#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();

        vector<int> remain;
        for(int j = 0; j < n; j++) {
            if(nums[j] > 0 || remain.empty()) {
                remain.push_back(nums[j]);
            }
            else {
                bool exists = true;
                while(!remain.empty() && remain.back() > 0 && exists) {
                    int value = abs(nums[j]);
                    if(value == remain.back()) {
                        remain.pop_back();
                        exists = false;
                    }
                    else if(value < remain.back()) {
                        exists = false;
                    }
                    else {
                        remain.pop_back();
                    }
                }

                if(exists)
                    remain.push_back(nums[j]);
            }
        }

        return remain;
    }
};