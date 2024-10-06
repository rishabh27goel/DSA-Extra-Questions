#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        stringstream firstSS(sentence1);
        stringstream secondSS(sentence2);
        string word;

        vector<string> first;
        while(firstSS >> word) {
            first.push_back(word);
        }

        vector<string> second;
        while(secondSS >> word) {
            second.push_back(word);
        }

        if(first.size() < second.size())
            return areSentencesSimilar(sentence2, sentence1);

        int left = 0;
        while(left < second.size() && first[left] == second[left])
            left++;

        int right1 = first.size() - 1;
        int right2 = second.size() - 1;

        while(right2 >= 0 && first[right1] == second[right2])
            right1--, right2--;

        return left > right2;
    }
};