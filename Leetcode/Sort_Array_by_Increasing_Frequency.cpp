#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<int> frequencySort(vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     int freq[201] = {0};
    //     for(int i=0; i<n; i++){
    //         freq[nums[i] + 100]++;
    //     }

    //     vector<pair<int, int>> freqPair;
    //     for(int i=0; i<201; i++){
    //         if(freq[i] == 0)  continue;

    //         freqPair.push_back(make_pair(freq[i], i - 100));
    //     }

    //     // Sort the frequency 
    //     sort(freqPair.begin(), freqPair.end(), [&](pair<int, int> &p1, pair<int, int> &p2){
    //         if(p1.first == p2.first)
    //             return p1.second > p2.second;

    //         return p1.first < p2.first;
    //     });

    //     int j = 0;
    //     for(int i=0; i<freqPair.size(); i++){
    //         int c = freqPair[i].first;
    //         while(c--){
    //             nums[j++] = freqPair[i].second;
    //         }
    //     }

    //     return nums;
    // }

    vector<int> frequencySort(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int freq[201] = {0};
        for(int i=0; i<n; i++){
            freq[nums[i] + 100]++;
        }

        // Sort the frequency 
        sort(nums.begin(), nums.end(), [&](int &a, int &b){
            if(freq[a + 100] == freq[b + 100])
                return a > b;
            
            return freq[a + 100] < freq[b + 100];
        });

        return nums;
    }
};