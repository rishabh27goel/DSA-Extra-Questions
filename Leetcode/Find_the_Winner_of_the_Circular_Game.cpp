#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int findTheWinner(int n, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     vector<int> removed(n, false);

    //     int left = n;
    //     int i = 0;
    //     while(left > 1){
        
    //         int j = 0;
    //         while(j < k){
    //             int idx = (i % n);
    //             if(removed[idx] == false){
    //                 j++;

    //                 if(j == k){
    //                     removed[idx] = true;
    //                     break;
    //                 }
    //             }
    //             i++;
    //         }
    //         left--;
    //     }   

    //     for(int i=0; i<n; i++){
    //         if(removed[i] == false)
    //             return i + 1;
    //     }

    //     return 0;
    // }

    // int findTheWinner(int n, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     // Add all the elements in the queue
    //     queue<int> q;
    //     for(int i=0; i<n; i++){
    //         q.push(i + 1);
    //     }

    //     while(q.size() > 1){
    //         // I have to pop k-1 elements 
    //         // And add them in the queue again
    //         for(int j=1; j<k; j++){
    //             q.push(q.front());
    //             q.pop();
    //         }

    //         // kth element removed
    //         q.pop();
    //     }

    //     return q.front();
    // }

    // Reverse thinking 

    // int findWinnerHelper(int n, int k){
    //     if(n == 1)
    //         return 0;

    //     int call = findWinnerHelper(n-1, k);
    //     return (call + k) % n;
    // }

    // int findTheWinner(int n, int k) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int index = findWinnerHelper(n , k);
    //     return index + 1;
    // }
    
    int findTheWinner(int n, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int prevIdx = 0;
        for(int idx = 2; idx <= n; idx++){
            prevIdx = (prevIdx + k) % idx;
        }

        return prevIdx + 1;
    }
};