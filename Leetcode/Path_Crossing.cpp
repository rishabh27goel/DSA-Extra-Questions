#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = path.size();

        // map<pair<int, int>, bool> mp; 
        unordered_set<string> visited;
        pair<int, int> origin = make_pair(0, 0);
        visited.insert("0,0");

        for(int i=0; i<n; i++){

            if(path[i] == 'N'){
                origin.second += 1;
            }
            else if(path[i] == 'S'){
                origin.second -= 1;
            }
            else if(path[i] == 'W'){
                origin.first += 1;
            }
            else{
                origin.first -= 1;
            }


            string key = to_string(origin.first) + "," + to_string(origin.second);

            if(visited.find(key) != visited.end())
                return true;

            visited.insert(key);
        }

        return false;
    }
};