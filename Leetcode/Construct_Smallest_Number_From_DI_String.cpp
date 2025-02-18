#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool createValidSequence(int size, string &pattern, string &sequence, vector<bool> &digitVisited, char prevChar, int currentIdx) {
        if(currentIdx == size)
            return true;
            
        for(int digit = 1; digit <= 9; digit++) {
            if(digitVisited[digit])  continue;

            char currentChar = (char) digit + '0';
            if((pattern[currentIdx] == 'I' && prevChar < currentChar) || (pattern[currentIdx] == 'D' && prevChar > currentChar)) {
                sequence.push_back(currentChar);
                digitVisited[digit] = true;


                if(createValidSequence(size, pattern, sequence, digitVisited, currentChar, currentIdx + 1))
                    return true;
                
                sequence.pop_back();
                digitVisited[digit] = false;
            }          
        }
        return false;
    }

    string smallestNumber(string pattern) {
        int size = pattern.size();

        vector<bool> digitVisited(10, false);
        string sequence = "";

        for(int start = 1; start <= 9; start++) {
            sequence.push_back((char) start + '0');
            digitVisited[start] = true;

            if(createValidSequence(size, pattern, sequence, digitVisited, (char) start + '0', 0))
                return sequence;

            sequence.pop_back();
            digitVisited[start] = false;
        }           

        return sequence;
    }
};