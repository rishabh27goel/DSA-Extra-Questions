#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }

        vector<int> freq;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            freq.push_back(itr->second);
        }

        sort(freq.begin(), freq.end());
        int result = 0;

        for(int i=0; i<freq.size(); i++){

            if(k - freq[i] < 0)
                break;

            k -= freq[i];
            result++;
        }

        return freq.size() - result;
    }

    // int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = arr.size();

    //     unordered_map<int, int> mp;
    //     for(int i=0; i<n; i++){
    //         mp[arr[i]]++;
    //     }

    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     for(auto itr = mp.begin(); itr != mp.end(); itr++){
    //         pq.push(itr->second);
    //     }

    //     int result = 0;
    //     while(!pq.empty()){

    //         int top = pq.top();
    //         pq.pop();

    //         if(k - top < 0)
    //             break;

    //         k -= top;
    //         result++;
    //     }

    //     return mp.size() - result;
    // }
};