#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = word.size();

        string comp = "";
        int j = 0;

        while(j < n) {
            char ch = word[j];
            int c = 0;

            while(j < n && ch == word[j] && c < 9) {
                c++, j++;
            }

            comp.push_back((char) ('0' + c));
            comp.push_back(ch);
        }

        return comp;
    }
};