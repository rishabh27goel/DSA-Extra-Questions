#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Using Dynamic Programming 
// Time Complexity : O(n ^ 2)   Space Complexity : O(n)
int findJumps(int n, vector<int> &arr, int ind, vector<int> &dp){

    // Base Case
    if(ind >= n-1)
        return 0;

    if(arr[ind] == 0)
        return -1;

    if(dp[ind] != -1)
        return dp[ind];

    int minJumps = INT_MAX;

    for(int j=1; j<=arr[ind]; j++){

        if(ind + j >= n)
            break;

        int jumps = findJumps(n, arr, ind+j, dp);
    
        if(jumps != -1)
            minJumps = min(jumps + 1, minJumps);
    }

    if(minJumps == INT_MAX)
        return -1;

    return dp[ind] = minJumps;  
}

int findMinimumJumps(vector<int> &arr){

    int n = arr.size();

   vector<int> dp(n, -1);

    return findJumps(n, arr, 0, dp);
} 

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Minimum Jumps
    int jumps = findMinimumJumps(arr);

    cout << "Minimum Jumps : " << jumps;


    cout << endl;
    return 0;
}