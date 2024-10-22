#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // unordered_map <string, int> unique;
    // int maxUnique = 0;

    // void uniqueSubstring(int n, string &str, int idx) {
    //     // Base Case
    //     if(idx == n) {
    //         maxUnique = max(maxUnique, (int) unique.size());
    //         return;
    //     }

    //     string sub = "";
    //     for(int j = idx; j < n; j++) {
    //         sub.push_back(str[j]);
    //         unique[sub]++;

    //         uniqueSubstring(n, str, j + 1);
    //         unique[sub]--;

    //         if(unique[sub] == 0)
    //             unique.erase(sub);
    //     }
    // }

    // int maxUniqueSplit(string str) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = str.size();

    //     uniqueSubstring(n, str, 0);
    //     return maxUnique;
    // }

    unordered_set <string> unique;
    int maxUnique = 0;

    void uniqueSubstring(int n, string &str, int idx) {
        // Base Case
        if(unique.size() + (n - idx) <= maxUnique)
            return;

        if(idx == n) {
            maxUnique = max(maxUnique, (int) unique.size());
            return;
        }

        string sub = "";
        for(int j = idx; j < n; j++) {
            sub.push_back(str[j]);
            if(unique.find(sub) == unique.end()) {
                unique.insert(sub);
                uniqueSubstring(n, str, j + 1);
                unique.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        uniqueSubstring(n, str, 0);
        return maxUnique;
    }
};