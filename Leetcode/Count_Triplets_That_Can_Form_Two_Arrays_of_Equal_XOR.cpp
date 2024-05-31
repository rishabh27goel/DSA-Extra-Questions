#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        int triplet = 0;
        for(int i=0; i<n-1; i++){

            int xorA = 0;
            for(int j=i; j<n; j++){

                xorA ^= arr[j];

                int xorB = 0;
                for(int k=j+1; k<n; k++){

                    xorB ^= arr[k];
                    if(xorA == xorB)
                        triplet++;                       
                }
            }
        }

        return triplet;
    }
};