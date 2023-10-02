#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        int n = colors.size();

        int aC = 0;
        int bC = 0;
        
        int i = 0;

        while(i < n){

            int c = 0;

            if(colors[i] == 'A'){

                while(i < n && colors[i] == 'A'){
                    c++;
                    i++;
                }

                aC += max(0, c-2);
            }
            else{

                while(i < n && colors[i] == 'B'){
                    c++;
                    i++;
                }
            
                bC += max(0, c-2);
            }
        }

        return aC > bC;
     }
};