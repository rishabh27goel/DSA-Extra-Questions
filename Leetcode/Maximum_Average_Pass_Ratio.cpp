#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        // If we look at the problem carefully 
        // a + b + c + d / 4  -> Total Avg. 
        // Now we want to increase the total avg, we want to find 
        // the maximum rise in numerator sum are the getting -> currentValue + 1 (Avg) - currentValue (Avg)
    
        using pp = pair<int, int>;
    
        class CustomCompare {
            public:
                bool operator()(auto &p1, auto &p2) {
                    auto findUpdateDifference = [](int pass, int total) {
                        return (double) (pass + 1) / (total + 1) - (double) pass / total;
                    };
    
                    double diffOne = findUpdateDifference(p1.first, p1.second);
                    double diffTwo = findUpdateDifference(p2.first, p2.second);
                    return diffOne < diffTwo;
                }
        };
    
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = classes.size();
    
            priority_queue<pp, vector<pp>, CustomCompare> pq;
            for(int currIdx = 0; currIdx < size; currIdx++) {
                pq.push({ classes[currIdx][0], classes[currIdx][1] });
            }
    
            while(extraStudents--) {
                auto currPair = pq.top();
                pq.pop();
    
                pq.push({ currPair.first + 1, currPair.second + 1 });
            }
    
            double totalAvg = 0;
            while(!pq.empty()) {
                auto currPair = pq.top();
                pq.pop();
    
                totalAvg += (1.0 * currPair.first / currPair.second);
            }
            return totalAvg / size;
        }
    };