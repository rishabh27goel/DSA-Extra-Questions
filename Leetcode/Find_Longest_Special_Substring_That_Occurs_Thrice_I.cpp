#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumLength(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        int maxLen = -1;
        vector<priority_queue<int, vector<int>, greater<int>>> charQueue(26);

        int j = 0;
        while(j < n) {
            char ch = str[j];
            int charCount = 0;

            while(j < n && ch == str[j]) {
                charCount++;
                j++;
            }

            auto &pq = charQueue[ch-'a'];
            pq.push(charCount);

            if(pq.size() > 3)   pq.pop();
            if(charCount >= 3)  maxLen = max(maxLen, charCount - 2);    
        }

        for(int j = 0; j < 26; j++) { 
            auto &pq = charQueue[j];
            if(pq.size() >= 3) {
                maxLen = max(maxLen, pq.top()); 
                pq.pop();
            }
            if(pq.size() == 2) {
                int first = charQueue[j].top();
                pq.pop();

                int second = charQueue[j].top();
                pq.pop();

                maxLen = max(maxLen, min(first, second - 1)); 
            }
        }

        return maxLen == 0 ? -1 : maxLen;
    }
};