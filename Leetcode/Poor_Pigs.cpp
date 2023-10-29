#include <iostream>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int t = minutesToTest / minutesToDie;

        float result = log(buckets) / log(t + 1);

        return ceil(result);
    }
};