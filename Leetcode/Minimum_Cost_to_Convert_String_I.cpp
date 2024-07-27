#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Solution {
public:
    // Floyd Warshall's algorithm
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<ll>> adjMat(26, vector<ll> (26));
        for(int i = 0; i < 26; i++){
            for(int j=0; j<26; j++){
                if(i == j) {
                    adjMat[i][j] = 0;
                }
                else {
                    adjMat[i][j] = 1e9;
                }
            }
        }

        for(int i = 0; i < original.size(); i++){
            int org = original[i]-'a';
            int change = changed[i]-'a';

            adjMat[org][change] = min(adjMat[org][change], (ll) cost[i]);
        }

        for(int via = 0; via < 26; via++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][via] + adjMat[via][j]);
                }   
            }
        }

        ll result = 0;
        for(int i=0; i<source.size(); i++){
            int s = source[i]-'a';
            int t = target[i]-'a';

            if(adjMat[s][t] >= 1e9)  return -1;
            result += adjMat[s][t];
        }

        return result;
    }
};