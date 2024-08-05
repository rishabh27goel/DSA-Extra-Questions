#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // string kthDistinct(vector<string>& arr, int k) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     cout.tie(NULL);

    //     unordered_map<string, int> freqMap;
    //     for(int i=0; i<arr.size(); i++){
    //         freqMap[arr[i]]++;
    //     }
        
    //     vector<string> distinct;
    //     for(int i=0; i<arr.size(); i++){
    //         if(freqMap[arr[i]] == 1)
    //             distinct.push_back(arr[i]);
    //     }

    //     return distinct.size() < k ? "" : distinct[k-1];
    // }

    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        unordered_map<string, int> freqMap;
        for(int i=0; i<arr.size(); i++){
            freqMap[arr[i]]++;
        }
        
        for(int i=0; i<arr.size(); i++){
            if(freqMap[arr[i]] == 1) {
                if(--k == 0)  return arr[i];
            }
        }

        return "";
    }
};