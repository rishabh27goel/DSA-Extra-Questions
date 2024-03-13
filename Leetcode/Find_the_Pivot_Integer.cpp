#include <iostream>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        
        int total = (n * (n + 1)) / 2;

        for(int j=1; j<=n; j++){
            
            int pivot = (j * (j-1)) / 2;

            if(total - j - pivot == pivot)
                return j;
        } 

        return -1;
    }
};