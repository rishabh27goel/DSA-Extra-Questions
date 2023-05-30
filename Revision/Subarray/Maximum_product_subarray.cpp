#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time : O(n^2)  Space : O(1)
// int findMaxProduct(vector<int> &arr){

//     int n = arr.size();

//     int maxProduct = INT_MIN;

//     for(int i=0; i<n; i++){

//         int product = 1;

//         for(int j=i; j<n; j++){

//             product *= arr[j];
        
//             maxProduct = max(product, maxProduct);
//         }
//     }

//     return maxProduct;
// }

// Method 2 : Linear Method
// Time : O(n)  Space : O(1)
int findMaxProduct(vector<int> &arr){

    int n = arr.size();

    long maxProduct = INT_MIN;

    long maxNum = INT_MIN;
    long minNum = INT_MAX;    

    for(int i=0; i<n; i++){

        if(arr[i] < 0)
            swap(maxNum, minNum);
    

        maxNum = max((long) arr[i], maxNum * (long) arr[i]);
        minNum = min((long) arr[i], minNum * (long) arr[i]);
        
        maxProduct = max(maxNum, maxProduct);
    }

    return maxProduct;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    int maxProduct = findMaxProduct(arr);

    cout << "Maximum Product Subarray : " << maxProduct;


    cout << endl;
    return 0;
}