#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n1 = arr1.size();
        int n2 = arr2.size();
    
        int countArr[1001] = {0};
        for(int i=0; i<n1; i++){
            countArr[arr1[i]]++;
        }

        int j = 0;
        for(int i=0; i<n2; i++){
            while(countArr[arr2[i]] > 0){
                arr1[j] = arr2[i];
                countArr[arr2[i]]--;
                j++;
            }
        }

        for(int i=0; i<1001; i++){
            if(countArr[i] == 0)
                continue;

            while(countArr[i] > 0){
                arr1[j] = i;
                countArr[i]--;
                j++;
            }
        }

        return arr1;
    }
};