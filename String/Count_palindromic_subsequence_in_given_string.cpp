#include <iostream>
using namespace std;

// Method : Using Dynamic Programming
// Time Complexity : O(n * n)  Space Complexity : O(n * n)
int dp[1000][1000];

int findCount(string &input, int i, int j){

    // Base Case
    if(i > j)
        return 0;

    if(i == j)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];


    // If we find any sequence which is palindromic 
    int count = 0;

    if(input[i] == input[j]){

        count = 1 + findCount(input, i+1, j) + findCount(input, i, j-1);
    }
    else{

        //  [1..5] + [0..4] - [1..4] (to avoid repetion) 

        count = findCount(input, i+1, j) + findCount(input, i, j-1) - findCount(input, i+1, j-1);
    }

    return dp[i][j] = count;
}

int countPalindromicSubsequences(string &input){

    int n = input.size();

    memset(dp, -1, sizeof(dp));
    
    return findCount(input, 0, n-1);
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    int total = countPalindromicSubsequences(input);

    cout << "Total Count : " << total;
    

    cout << endl; 
    return 0;
}