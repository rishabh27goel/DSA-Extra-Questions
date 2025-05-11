#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool threeConsecutiveOdds(vector<int>& arr) {
            int size = arr.size();
    
            int idx = 0;
            while(idx < size) {
                if(arr[idx] % 2 == 0) {
                    idx++;
                }
                else {
                    int count = 0;
                    while(idx < size && arr[idx] % 2 == 1) {
                        count++, idx++;
                    }
                    if(count >= 3)  return true;
                }
            }
            return false;
        }
    };