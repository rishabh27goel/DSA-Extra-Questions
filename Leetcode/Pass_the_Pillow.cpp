#include <iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        
        int window = 2 * (n-1);
        time = time % window;

        if(time <= n-1){
            return 1 + time;
        }
        else {
            time = time % (n-1);
            return n - time;
        }
    }
};