#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         ios_base::sync_with_stdio(false);
//         // cin.tie(NULL);
//         // cout.tie(NULL);

//         int n = arr.size();

//         unordered_map<int, int> mp;
//         for(int j = 0; j < n; j++) {
//             mp[((arr[j] % k) + k) % k]++;
//         }

//         for(int j = 0; j < n; j++) {
//             int hash = ((arr[j] % k) + k) % k;
//             if(hash == 0) {
//                 if(mp[hash] % 2 == 1)
//                     return false;
//             }
//             else if(mp[hash] != mp[k - hash])
//                 return false;
//         }

//         return true;
//     }
// };

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         ios_base::sync_with_stdio(false);
//         // cin.tie(NULL);
//         // cout.tie(NULL);

//         int n = arr.size();

//         vector<int> mp(k, 0);

//         for(int j = 0; j < n; j++) {
//             mp[((arr[j] % k) + k) % k]++;
//         }

//         for(int j = 0; j < n; j++) {
//             int hash = ((arr[j] % k) + k) % k;
//             if(hash == 0) {
//                 if(mp[hash] % 2 == 1)
//                     return false;
//             }
//             else if(mp[hash] != mp[k - hash])
//                 return false;
//         }

//         return true;
//     }
// };

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);

//         int n = arr.size();

//         vector<int> mp(k, 0);
//         for(int j = 0; j < arr.size(); j++) {
//             int hash = (arr[j] % k + k) % k;
//             int rem = (k - hash) % k;

//             if(mp[rem] > 0) {
//                 mp[rem]--;
//             }   
//             else {
//                 mp[hash]++;
//             }
//         }

//         for(int j = 0; j < k; j++) {
//             if(mp[j] != 0)  return false;
//         }
                
//         return true;
//     }
// };

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        vector<int> mp(k, 0);
        int pairs = 0;

        for(int j = 0; j < arr.size(); j++) {
            int hash = (arr[j] % k + k) % k;
            int rem = (k - hash) % k;

            if(mp[rem] > 0) {
                pairs++;
                mp[rem]--;
            }   
            else {
                mp[hash]++;
            }
        }
                
        return pairs == (n / 2);
    }
};