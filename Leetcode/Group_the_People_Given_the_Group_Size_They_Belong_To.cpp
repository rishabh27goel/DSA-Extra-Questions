#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = groupSizes.size();

    //     vector<vector<int>> result;
    //     unordered_map<int, vector<int>> mp;

    //     for(int i=0; i<n; i++){

    //         mp[groupSizes[i]].push_back(i);
    //     }
        
    //     for(auto itr = mp.begin(); itr != mp.end(); itr++){

    //         int size = itr->first;
    //         int maxSize = itr->second.size();

    //         int total = 0;

    //         while(total < maxSize){

    //             vector<int> sub;

    //             for(int i = total; i < total + size; i++){

    //                 sub.push_back(itr->second[i]);
    //             }

    //             total += size;
    //             result.push_back(sub);
    //         }
    //     }

    //     return result;
    // }

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = groupSizes.size();

        vector<vector<int>> result;
        // unordered_map<int, vector<int>> mp;
        vector<int> mp[n + 1];
        
        for(int i=0; i<n; i++){

            auto &vt = mp[groupSizes[i]];
            vt.push_back(i);

            if(vt.size() == groupSizes[i]){

                result.push_back(vt);
                vt.clear();
            }
        }

        return result;
    }
};