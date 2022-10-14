#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O(2 ^ n)   Space Complexity : O(n)
// int findMaxSlices(int n, vector<int> &slices, int k, int ind){

//     // Base Case
//     if(ind >= n || k == 0)
//         return 0;

//     // Skip adjacent index
//     int include = slices[ind] + findMaxSlices(n, slices, k-1, ind+2);

//     // If we exclude current index
//     int exclude = findMaxSlices(n, slices, k, ind+1);

    
//     return max(include, exclude);
// }

// int maximumSlices(vector<int> &slices){

//     int n = slices.size();
//     int k = n/3;

//     int firstStart = findMaxSlices(n-1, slices, k, 0);
//     int secondStart = findMaxSlices(n, slices, k, 1);


//     return max(firstStart, secondStart);
// }

// Method 2 : Dynamic Programming & Memoisation
// Time Complexity : O(k * n)   Space Complexity : O(k * n)
// int findMaxSlices(int n, vector<int> &slices, int k, int ind, vector<vector<int>> &dp){

//     // Base Case
//     if(ind >= n || k == 0)
//         return 0;

//     // Step 3 : Already Exists
//     if(dp[k][ind] != -1)
//         return dp[k][ind];


//     // Skip adjacent index
//     int include = slices[ind] + findMaxSlices(n, slices, k-1, ind+2, dp);

//     // If we exclude current index
//     int exclude = findMaxSlices(n, slices, k, ind+1, dp);

    
//     // Step 2 : Store in dp array
//     dp[k][ind] = max(include, exclude);


//     return dp[k][ind];
// }

// int maximumSlices(vector<int> &slices){

//     int n = slices.size();
//     int k = n/3;

//     // Step 1 : Create dp array 
//     vector<vector<int>> firstDp(k+1, vector<int> (n, -1));
    
//     int firstStart = findMaxSlices(n-1, slices, k, 0, firstDp);
    

//     vector<vector<int>> secondDp(k+1, vector<int> (n, -1));
    
//     int secondStart = findMaxSlices(n, slices, k, 1, secondDp);


//     return max(firstStart, secondStart);
// }

// Method 3 : Dynamic Programming & Tabulation
// Time Complexity : O(k * n)   Space Complexity : O(k * n)
// int maximumSlices(vector<int> &slices){

//     int n = slices.size();
//     int pn = n/3;

//     // Step 1 : Create dp array 
//     vector<vector<int>> firstDp(pn+1, vector<int> (n+2, 0));
    
//     // Step 2 : Tabulation
//     for(int k=1; k<=pn; k++){

//         for(int ind=n-2; ind>=0; ind--){

//             // Skip adjacent index
//             int include = slices[ind] + firstDp[k-1][ind+2];

//             // If we exclude current index
//             int exclude = firstDp[k][ind+1];

            
//             firstDp[k][ind] = max(include, exclude);
//         }
//     }
    

//     vector<vector<int>> secondDp(pn+1, vector<int> (n+2, 0));
    
//     for(int k=1; k<=pn; k++){

//         for(int ind=n-1; ind>=1; ind--){

//             // Skip adjacent index
//             int include = slices[ind] + secondDp[k-1][ind+2];

//             // If we exclude current index
//             int exclude = secondDp[k][ind+1];

            
//             secondDp[k][ind] = max(include, exclude);
//         }
//     }

//     return max(firstDp[pn][0], secondDp[pn][1]);
// }

// Method 4 : Space Optimisation
// Time Complexity : O(k * n)   Space Complexity : O(4 * n)
int maximumSlices(vector<int> &slices){

    int n = slices.size();
    int pn = n/3;

    // Step 1 : Create dp array 
    vector<int> firstPrev(n+2, 0);
    vector<int> firstCurr(n+2, 0);
    
    // Step 2 : Tabulation
    for(int k=1; k<=pn; k++){

        for(int ind=n-2; ind>=0; ind--){

            // Skip adjacent index
            int include = slices[ind] + firstPrev[ind+2];

            // If we exclude current index
            int exclude = firstCurr[ind+1];


            firstCurr[ind] = max(include, exclude);
        }

        firstPrev = firstCurr;
    }
    

    vector<int> secondPrev(n+2, 0);
    vector<int> secondCurr(n+2, 0);
    
    for(int k=1; k<=pn; k++){

        for(int ind=n-1; ind>=1; ind--){

            // Skip adjacent index
            int include = slices[ind] + secondPrev[ind+2];

            // If we exclude current index
            int exclude = secondCurr[ind+1];


            secondCurr[ind] = max(include, exclude);
        }

        secondPrev = secondCurr;
    }

    return max(firstPrev[0], secondPrev[1]);
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> slices(size);

    for(int i=0; i<size; i++){

        cin >> slices[i];
    }

    // Pizza With 3n Slices
    int sum = maximumSlices(slices);

    cout << "Maximum Sum : " << sum;

    cout << endl;
    return 0;
}