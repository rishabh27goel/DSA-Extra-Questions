#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = nums.size();

    //     unordered_map<int, int> numsMap;
    //     for(int i=0; i<n; i++){
    //         int newVal = 0;
    //         int number = nums[i];

    //         if(number == 0){
    //             newVal = mapping[0];
    //         }
    //         else {
    //             int mul = 1;
    //             while(number > 0){
    //                 int dig = number % 10;
    //                 newVal = (mapping[dig] * mul) + newVal;
    //                 number /= 10;
    //                 mul *= 10;
    //             }
    //         }
        
    //         numsMap[nums[i]] = newVal;
    //     }

    //     sort(nums.begin(), nums.end(), [&](int &n1, int &n2){
    //         return numsMap[n1] < numsMap[n2];
    //     });

    //     return nums;
    // }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();

        vector<pair<int, int>> mappedPair;
        for(int i=0; i<n; i++){
            int newVal = 0;
            int number = nums[i];

            if(number == 0) {
                newVal = mapping[0];
            }
            else {
                int mul = 1;
                while(number > 0){
                    int dig = number % 10;
                    newVal = (mapping[dig] * mul) + newVal;
                    number /= 10;
                    mul *= 10;
                }
            }
            mappedPair.push_back(make_pair(newVal, i));
        }

        sort(mappedPair.begin(), mappedPair.end(), [&](pair<int, int> &p1, pair<int, int> &p2){
            if(p1.first == p2.first)
                return p1.second < p2.second;

            return p1.first < p2.first;
        });

        vector<int> result;
        for(int i=0; i<n; i++){
            result.push_back(nums[mappedPair[i].second]);
        }

        return result;
    }
};