#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){

            mp[arr[i]]++;
        }

        unordered_set<int> exists;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){

            if(exists.find(itr->second) != exists.end())
                return false;

            exists.insert(itr->second);
        }   

        return true;
    }
};