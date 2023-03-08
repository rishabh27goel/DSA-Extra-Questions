#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(maximum element * n)  Space Complexity : O(1)
// int findMinimumInteger(vector<int> &arr, int h){

//     int n = arr.size();

//     int maxNum = INT_MIN;

//     for(int i=0; i<n; i++){

//         maxNum = max(arr[i], maxNum);
//     }

//     for(int k=1; k<=maxNum; k++){

//         int total = 0;

//         for(int i=0; i<n; i++){

//             total += (arr[i] / k);

//             if(arr[i] % k != 0)
//                 total++;
//         }

//         if(total <= h)
//             return k;
//     }

//     return -1;
// }

// Method 2 : Using Binary Search
// Time Complexity : O(n * log(maximum element))  Space Complexity : O(1)
int findMinimumInteger(vector<int> &arr, int h){

    int n = arr.size();

    int maxNum = INT_MIN;

    for(int i=0; i<n; i++){

        maxNum = max(arr[i], maxNum);
    }

    int index = -1;
    int start = 1;
    int end = maxNum;

    while(start <= end){

        int k = start + (end - start) / 2;

        int total = 0;

        for(int i=0; i<n; i++){

            total += (arr[i] / k);

            if(arr[i] % k != 0)
                total++;
        }

        if(total > h){

            start = k + 1;
        }
        else{

            index = k;
            end = k - 1;
        }
    }

    return index;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter total hours : ";
    int h;
    cin >> h;

    // Koko Eating Bananas
    int minInt = findMinimumInteger(arr, h);

    cout << "Minimum Integer : " << minInt;


    cout << endl;
    return 0;
}