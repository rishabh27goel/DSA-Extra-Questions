#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string str, int repeatLimit) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = str.size();

        int charCount[26] = {0};
        for(int j = 0; j < n; j++) {
            charCount[str[j]-'a']++;
        }

        priority_queue<pair<char, int>> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(charCount[i] == 0)   continue;
            maxHeap.push({(char) (i + 'a'), charCount[i]});
        }

        string lexiStr = "";

        while(!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int size = min(top.second, repeatLimit);
            lexiStr.append(size, top.first);

            if(maxHeap.empty())
                break;

            if(top.second - size > 0) {
                auto smallest = maxHeap.top();
                maxHeap.pop();

                lexiStr.append(1, smallest.first);

                if(smallest.second - 1 > 0)    
                    maxHeap.push({smallest.first, smallest.second - 1});

                maxHeap.push({top.first, top.second - size});
            }            
        }

        return lexiStr;
    }
};