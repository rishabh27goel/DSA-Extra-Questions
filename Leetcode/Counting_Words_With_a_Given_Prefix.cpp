#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();

        int prefCount = 0;
        for(int i = 0; i < n; i++) {
            int j = 0;
            int k = 0;

            while(j < pref.size() && k < words[i].size()) {
                if(pref[j] != words[i][k])
                    break;

                j++;
                k++;
            }
        
            if(j == pref.size())
                prefCount++;
        }

        return prefCount;
    }
};