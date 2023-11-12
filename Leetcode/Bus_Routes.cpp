#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target)
            return 0;

        int maxStop = -1;

        for(int i=0; i<routes.size(); i++){

            for(int j=0; j<routes[i].size(); j++){

                maxStop = max(routes[i][j], maxStop);
            }
        }
        
        if(target > maxStop)
            return -1;

        vector<int> minBuses(maxStop + 1, routes.size() + 1);
        minBuses[source] = 0;

        bool update = true;

        while(update){

            update = false;

            // Any node which is visited and has some min buses value
            for(int i=0; i<routes.size(); i++){

                int buses = routes.size() + 1;

                for(int j=0; j<routes[i].size(); j++){

                    buses = min(buses, minBuses[routes[i][j]]);
                }

                buses++;

                // For all the remaining nodes of the iteation

                for(int j=0; j<routes[i].size(); j++){

                    if(buses < minBuses[routes[i][j]]){

                        minBuses[routes[i][j]] = buses;
                        update = true;
                    }
                }
            }

            // Nothing updated (No path forward from source) (if update is false)
        }

        if(minBuses[target] == routes.size() + 1)
            return -1;

        return minBuses[target];
    }
};