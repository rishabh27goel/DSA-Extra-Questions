#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTotalWays(vector<int> &tileCharCount, int currLength) {
        if(currLength >= tileCharCount.size())
            return 0;

        int currWays = (currLength > 0);
        for(int charIdx = 0; charIdx < 26; charIdx++) {
            if(tileCharCount[charIdx] == 0) continue;

            tileCharCount[charIdx]--;
            currWays += findTotalWays(tileCharCount, currLength + 1);
            tileCharCount[charIdx]++;
        }
        return currWays;
    }

    int numTilePossibilities(string tiles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int tileSize = tiles.size();

        vector<int> tileCharCount(26, 0);
        for(int tileIdx = 0; tileIdx < tileSize; tileIdx++) {
            tileCharCount[tiles[tileIdx]-'A']++;
        }   

        return findTotalWays(tileCharCount, 0);
    }
};