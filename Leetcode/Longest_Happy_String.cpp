#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue <pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string str = "";
        while(!pq.empty()) {
            auto topPr = pq.top();
            pq.pop();

            int count = topPr.first;
            char letter = topPr.second;

            int size = str.size();
            if(str.size() >= 2 && str[size-1] == letter && str[size-2] == letter) {
                if(pq.empty())
                    break;

                auto secPr = pq.top();
                pq.pop();

                int secCount = secPr.first;
                char secLetter = secPr.second;

                secCount--;
                str.push_back(secLetter);

                if(secCount > 0)  pq.push({secCount, secLetter});
                if(count > 0)  pq.push({count, letter});
            }
            else {
                count--;
                str.push_back(letter);

                if(count > 0)  pq.push({count, letter});
            }
        }

        return str;
    }
};