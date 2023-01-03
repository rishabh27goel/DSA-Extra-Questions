#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// int missingNumber(vector<int> &arr, int n){

//     // Sort the array
//     sort(arr.begin(), arr.end());

//     int inc = 1;
//     int i = 0;

//     while(i < arr.size()){

//         if(arr[i] != inc)
//             return inc;

//         inc++;
//         i++;
//     }

//     return inc;
// }

// Method 2 : Using XOR
// Time Complexity : O(n)  Space Complexity : O(1)
int findXor(int n){

    if(n % 4 == 0)
        return n;
    else if(n % 4 == 1)
        return 1;
    else if(n % 4 == 2)
        return n+1;
    
    return 0;
}

int missingNumber(vector<int> &arr, int n){

    int totalXor = findXor(n);
    int xorArr = 0;

    for(int i=0; i<arr.size(); i++){

        xorArr ^= arr[i];
    }

    return totalXor ^ xorArr;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> arr(n-1);

    for(int i=0; i<n-1; i++){

        cin >> arr[i];
    }


    // Missing number
    int number = missingNumber(arr, n);

    cout << "Missing Number : " << number;


    cout << endl;
    return 0;
}