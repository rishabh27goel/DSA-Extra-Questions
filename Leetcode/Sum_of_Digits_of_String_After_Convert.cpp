#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();

        int totalSum = 0;
        for(int j = 0; j < n; j++) {
            int intVal = (s[j] - 'a') + 1;
        
            totalSum += (intVal % 10);
            intVal /= 10;
            totalSum += (intVal % 10);
        }   

        if(k-- == 1)  return totalSum;

        while(k--) {
            int currSum = 0;
            while(totalSum > 0) {
                currSum += (totalSum % 10);
                totalSum /= 10;
            }
            totalSum = currSum;
        }

        return totalSum;
    }
};