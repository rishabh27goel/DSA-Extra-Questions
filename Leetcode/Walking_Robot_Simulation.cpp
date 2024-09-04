#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long MUL = 60001;
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = commands.size();

        unordered_set<long> obsSet;
        for(int j = 0; j < obstacles.size(); j++) {
            obsSet.insert(obstacles[j][0] * MUL + obstacles[j][1]);
        }

        int xPos[4] = {0, 1, 0, -1};
        int yPos[4] = {1, 0, -1, 0};

        pair<int, int> currPos = make_pair(0, 0); 
        int dir = 0;    // North

        int maxDistance = 0;
        for(int j = 0; j < commands.size(); j++) {
            if(commands[j] == -1) {
                dir = (dir + 1) % 4;
            }
            else if(commands[j] == -2) {
                dir = (dir + 4 - 1) % 4;
            }
            else {
                int step = commands[j];
                for(int c = 1; c <= step; c++) {
                    int newX = xPos[dir] + currPos.first;
                    int newY = yPos[dir] + currPos.second;
                
                    if(obsSet.find(newX * MUL + newY) != obsSet.end()) 
                        break;

                    currPos = make_pair(newX, newY);
                    maxDistance = max(newX * newX + newY * newY, maxDistance);
                }
            }
        }

        return maxDistance;
    }
};