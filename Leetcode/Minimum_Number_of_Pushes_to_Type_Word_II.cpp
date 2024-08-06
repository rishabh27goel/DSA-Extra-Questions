#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = word.size();

        vector<int> freqCount(26, 0);
        for(char ch : word){
            freqCount[ch - 'a']++;
        }

        sort(freqCount.begin(), freqCount.end(), greater<int> ());

        int times = 0;
        int cost = 1;

        int totalCost = 0;
        int j = 0;

        while(j < 26){
            if(freqCount[j] == 0)  break;

            totalCost += (freqCount[j] * cost);
            j++, 
            times++;

            if(times == 8) {
                cost++;
                times = 0;
            }
        }

        return totalCost;
    }
};