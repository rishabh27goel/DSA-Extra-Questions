#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = tokens.size();
        sort(tokens.begin(), tokens.end());

        int result = 0;
        int score = 0;

        int i = 0;
        int j = n-1;

        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
            }
            else {

                if(score == 0)
                    break;

                power += tokens[j--];
                score--;
            }

            result = max(score, result);
        }

        return result;
    }
};