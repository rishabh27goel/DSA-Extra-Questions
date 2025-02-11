#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubstringMatchFound(string &remaining, string &part) {
        int remSize = remaining.size();
        int partSize = part.size();
        
        if(remSize < partSize)
            return false;

        int remIdx = remSize - 1;
        int partIdx = partSize - 1;

        while(partIdx >= 0) {
            if(remaining[remIdx] != part[partIdx])
                break;

            remIdx--, partIdx--;
        }

        return partIdx < 0;
    }

    string removeOccurrences(string s, string part) {
        int size = s.size();

        string remaining = "";
        for(int idx = 0; idx < size; idx++) {
            remaining.push_back(s[idx]);

            if(isSubstringMatchFound(remaining, part)) {
                // Now we can remove substring of size part from remaining string
                int partSize = part.size();
                while(partSize) {
                    remaining.pop_back();
                    partSize--;
                }
            }
        }

        return remaining;
    }
};