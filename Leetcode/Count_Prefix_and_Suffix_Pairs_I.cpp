#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool prefixSuffix(string &match, string &target) {
        if(target.size() < match.size())
            return false;

        int i = 0;
        int j = 0;

        while(i < match.size() && j < target.size()) {
            if(match[i] != target[j])
                break;
    
            i++;
            j++;
        }

        if(i != match.size())
            return false;

        i = match.size()-1;
        j = target.size()-1;

        while(i >= 0 && j >= 0) {
            if(match[i] != target[j])
                break;
    
            i--;
            j--;
        }

        return i < 0;  
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int pairs = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(prefixSuffix(words[i], words[j])) {
                    pairs++;
                }
            }
        }
        return pairs;
    }
};