#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();

        vector<string> result;
        int j = 0;
        while(j < n){

            long start = nums[j];
            long end = nums[j];
            long number = nums[j];

            while(j < n && number == nums[j]){
                end = nums[j];
                number++, j++;
            }
            
            if(start == end) {
                result.push_back(to_string(start));
            }
            else {
                result.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        return result;
    }
};