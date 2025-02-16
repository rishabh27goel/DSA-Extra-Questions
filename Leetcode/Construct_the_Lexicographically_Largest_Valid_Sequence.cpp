#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool constructSeqHelper(int size, vector<int> &sequence, vector<bool> &filledNumbers, int seqIdx) {
        if(seqIdx == sequence.size())
            return true;

        if(sequence[seqIdx] != -1)
            return constructSeqHelper(size, sequence, filledNumbers, seqIdx + 1);

        for(int idx = size; idx >= 1; idx--) {
            if(filledNumbers[idx])  continue;

            if(idx == 1 || (seqIdx + idx < sequence.size() && sequence[seqIdx + idx] == -1)) {
                filledNumbers[idx] = true;
                sequence[seqIdx] = idx;
                if(idx != 1)   sequence[seqIdx + idx] = idx;

                if(constructSeqHelper(size, sequence, filledNumbers, seqIdx + 1)) {
                    return true;
                }

                // Backtracking
                filledNumbers[idx] = false;
                sequence[seqIdx] = -1;
                if(idx != 1)   sequence[seqIdx + idx] = -1;
            }
        } 

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<bool> filledNumbers(n + 1, false);
        vector<int> sequence((2 * n) - 1, -1);

        constructSeqHelper(n, sequence, filledNumbers, 0);
        return sequence;
    }
};