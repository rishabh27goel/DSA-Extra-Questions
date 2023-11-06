#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getWinner(vector<int>& arr, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        int maxNum = max(arr[0], arr[1]);
        int c = 1;

        if(k == 1)
            return maxNum;


        for(int i=2; i<n; i++){

            // New max found
            if(maxNum < arr[i]){

                maxNum = arr[i];
                c = 1;
            }
            else{

                c++;
            }

            if(c >= k)
                return maxNum;
        }   

        return maxNum;  
    }
};