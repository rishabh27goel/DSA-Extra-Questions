#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 3)  Space Complexity : O(1)
// vector<int> tripletSum(vector<int> &arr, int target){

//     int n = arr.size();

//     vector<int> triplet;

//     for(int i=0; i<n; i++){

//         for(int j=i+1; j<n; j++){

//             for(int k=j+1; k<n; k++){

//                 if(arr[i] + arr[j] + arr[k] == target){

//                     triplet.push_back(arr[i]);
//                     triplet.push_back(arr[j]);
//                     triplet.push_back(arr[k]);

//                     return triplet;
//                 }
//             }
//         }
//     }

//     return triplet;
// }

// Method 2 : Using Unordered Map
// Time Complexity : O(n ^ 2)  Space Complexity : O(n)
// vector<int> tripletSum(vector<int> &arr, int target){

//     int n = arr.size();

//     vector<int> triplet;

//     for(int i=0; i<n; i++){

//         unordered_map<int, int> mp;
//         int sum = target - arr[i];

//         for(int j=i+1; j<n; j++){

//             if(mp.find(sum - arr[j]) != mp.end()){

//                 triplet.push_back(arr[i]);
//                 triplet.push_back(sum - arr[j]);
//                 triplet.push_back(arr[j]);

//                 return triplet;
//             }

//             mp[arr[j]] = j;
//         }
//     }

//     return triplet;
// }

// Method 3 : Sorting Array and Two Pointer
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
vector<int> tripletSum(vector<int> &arr, int target){

    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());


    vector<int> triplet;

    for(int k=0; k<n; k++){

        int sum = target - arr[k];

        int i = k+1;
        int j = n-1;

        while(i < j){

            if(arr[i] + arr[j] == sum){

                triplet.push_back(arr[k]);
                triplet.push_back(arr[i]);
                triplet.push_back(arr[j]);

                return triplet;
            }
            else if(arr[i] + arr[j] > sum){

                j--;
            }
            else{

                i++;
            }
        }
    }

    return triplet;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter array : ";
    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    // Triplet Sum in Array
    vector<int> triplet = tripletSum(arr, target);

    cout << "Triplet : ";
    
    for(int i=0; i<triplet.size(); i++){

        cout << triplet[i] << " ";
    }

    cout << endl;
    return 0;
}