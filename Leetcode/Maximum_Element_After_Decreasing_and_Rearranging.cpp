#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        ios_base::sync_with_stdio(false);

        int n = arr.size();

        vector<int> count(n+1, 0);

        for(int i=0; i<n; i++){

            count[min(arr[i], n)]++;
        }

        int result = 1;

        for(int num=2; num<=n; num++){

            result = min(result + count[num], num);
        }

        return result;
    }

    // int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

    //     int n = arr.size();

    //     // Sort the array
    //     sort(arr.begin(), arr.end());

    //     int result = 1;

    //     for(int i=1; i<n; i++){

    //         if(arr[i] >= result + 1){

    //             result++;
    //         }
    //     }

    //     return result;
    // }

    // int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
    //     int n = arr.size();

    //     // Sort the array
    //     sort(arr.begin(), arr.end());

    //     int result = 1;
    //     int prev = 1;

    //     int i = 1;

    //     // Iterate all ones
    //     while(i < n && arr[i] == prev){

    //         i++;
    //     }

    //     while(i < n){

    //         int curr = arr[i];
    //         int c = 0;

    //         while(i < n && arr[i] == curr){

    //             c++;
    //             i++;
    //         }

    //         if(prev + 1 == curr){

    //             prev++;
    //             result = max(result, prev);
    //         }
    //         else {

    //             if(prev + c >= curr) {
    //                 result = max(curr, result);
    //             } 
    //             else {

    //                 prev++;
    //                 result = max(result, prev);
    //             }             
    //         }
    //     }

    //     return result;        
    // }
};