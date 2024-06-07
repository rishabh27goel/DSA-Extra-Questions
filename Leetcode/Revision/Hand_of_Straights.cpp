#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        unordered_map<int, int> handCount;
        for(int i=0; i<n; i++){
            handCount[hand[i]]++;
        }

        for(auto card: hand){

            if(handCount[card] == 0)
                continue;

            // Find the start card
            int startCard = card;
            while(handCount[startCard-1] > 0){
                startCard--;
            }

            int items = groupSize;
            while(items--){

                if(handCount[startCard] > 0)
                    handCount[startCard]--;
                else
                    return false;

                startCard++;
            }
        }

        return true;
    }
};