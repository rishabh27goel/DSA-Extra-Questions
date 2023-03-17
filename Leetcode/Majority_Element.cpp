#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int majorityElement(vector<int> &arr){

//     int n = arr.size();

//     for(int i=0; i<n; i++){

//         int c = 0;

//         for(int j=0; j<n; j++){

//             if(arr[i] == arr[j])
//                 c++;
//         }

//         if(c > n/2)
//             return arr[i];
//     }

//     return -1;
// }

// Method 2 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(n)
// int majorityElement(vector<int> &arr){

//     int n = arr.size();

//     unordered_map<int, int> mp;

//     for(int i=0; i<n; i++){

//         mp[arr[i]]++;
//     }

//     for(auto itr = mp.begin(); itr != mp.end(); itr++){

//         if(itr->second > n/2)
//             return itr->first;
//     }

//     return -1;
// }

// Method 3 : Moore's Voting Algorithm
// Time Complexity : O(n)  Space Complexity : O(1)
int majorityElement(vector<int> &arr){

    int n = arr.size();

    // Step :
    // 1. Select any candidate
    // 2. Maintain count [Element equal to candidate]
    // 3. Positive votes : Candidate has Majority [else count will be zero repart steps from next element] 

    int c = 0;
    int candidate = -1;

    for(int i=0; i<n; i++){

        if(c == 0){

            candidate = arr[i];
            c = 1;
        }
        else{

            if(arr[i] == candidate){

                c++;
            }
            else{

                c--;
            }
        }
    }

    return candidate;
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

    // Majority Element
    int element = majorityElement(arr);

    cout << "Majority Element : " << element;


    cout << endl;
    return 0;
}