#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int maximizeOnes(vector<int> &arr, int m){

//     int n = arr.size();

//     int maxCount = 0;

//     for(int i=0; i<n; i++){

//         int one = 0;
//         int zero = 0;

//         for(int j=i; j<n; j++){

//             if(arr[j] == 0){

//                 zero++;
//             }
//             else{

//                 one++;
//             }

//             if(zero <= m){

//                 maxCount = max(j - i + 1, maxCount);
//             }
//         }
//     }

//     return maxCount;
// }

// Method 2 : Sliding Window
// Time Complexity : O(n)  Space Complexity : O(1)
int maximizeOnes(vector<int> &arr, int m){

    int n = arr.size();

    int maxCount = 0;
    int count = 0;

    int i = 0;
    int j = 0;

    while(i < n){

        if(arr[i] == 0)
            count++;

        while(j < i && count > m){

            if(arr[j] == 0)
                count--;

            j++;
        }

        maxCount = max(i-j+1, maxCount);

        i++;
    }
    

    return maxCount;
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

    cout << "Enter m : ";
    int m;
    cin >> m;


    // Maximize Ones
    int ones = maximizeOnes(arr, m);

    cout << "Number of Ones : " << ones;

    cout << endl;
    return 0;
}