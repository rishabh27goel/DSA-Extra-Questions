#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        ios_base::sync_with_stdio(false);

        int n = deck.size();

        // Sort the deck
        sort(deck.begin(), deck.end(), greater<int> ());

        queue<int> q;
        q.push(deck[0]);        

        for(int i=1; i<n; i++){

            int front = q.front();
            q.pop();

            q.push(front);
            q.push(deck[i]);
        }


        vector<int> result(q.size());
        int idx = n-1;

        while(!q.empty()){
            result[idx] = q.front();
            idx--;
            q.pop();
        }

        return result;
    }
};