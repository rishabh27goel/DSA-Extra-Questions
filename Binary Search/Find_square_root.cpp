#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Iterating till square root
// Time Complexity : O(sqrt(n))   Space Complexity : O(1) 
// int findSquareRoot(int n){

//     int i = 1;

//     while(i * i <= n){

//         i++;
//     }

//     return i-1;
// }

// Method 2 : Binary Search
// Time Complexity : O(log(n))   Space Complexity : O(1) 
int findSquareRoot(int n){

    int i = 0;
    int j = n;

    int square = 0;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(mid * mid == n)
            return mid;

        if(mid * mid > n){

            j = mid - 1;
        }
        else{

            square = mid;
            i = mid + 1;
        }
    }

    return square;
}

int main()
{
    cout << "Enter Input Number : ";
    int n;
    cin >> n;

    
    // Find Square Root
    int sqRoot = findSquareRoot(n);

    cout << "Square Root : " << sqRoot;


    cout << endl;
    return 0;
}