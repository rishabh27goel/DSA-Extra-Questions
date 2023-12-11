#include <iostream>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = arr.size();

        int i = 0;

        while(i < n){

            int c = 0;
            int val = arr[i];

            while(i < n && val == arr[i]){

                c++;
                i++;
            }

            if(c > n/4)
                return val;
        }

        return -1;
    }
};