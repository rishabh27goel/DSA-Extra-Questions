#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int maximumProductSubarray(vector<int> &arr){

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
// Time Complexity : O(n)  Space Complexity : O(1)
int maximumProductSubarray(vector<int> &arr){

    int n = arr.size();

    int product = arr[0];

    int maxi = arr[0];
    int mini = arr[0];

    for(int i=1; i<n; i++){

        if(arr[i] < 0)
            swap(maxi, mini);

        maxi = max(arr[i], arr[i] * maxi);
        mini = min(arr[i], arr[i] * mini);

        product = max(maxi, product);
    }

    return product;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter array : ";
    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Maximum Product Subarray 
    int product = maximumProductSubarray(arr);

    cout << "Maximum Product : " << product;


    cout << endl;
    return 0;
}