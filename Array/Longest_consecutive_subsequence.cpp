#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Method 1 : Sorting the array
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// int longestConsecutiveSubsequence(vector<int> &arr){

//     int n = arr.size();

//     // Sort the array
//     sort(arr.begin(), arr.end());

//     int longest = 0;
//     int i = 0;

//     while(i < n){

//         int count = 0;

//         while(i < n-1 && arr[i+1] == arr[i] + 1){

//             count++;
//             i++;

//             while(i < n-1 && arr[i] == arr[i+1]){

//                 i++;
//             }
//         }

//         longest = max(count+1, longest);
//         i++;
//     }

//     return longest;
// }


// Method 2 : Using Unordered Set
// Time Complexity : O(n)  Space Complexity : O(n)
int longestConsecutiveSubsequence(vector<int> &arr){

    int n = arr.size();

    unordered_set<int> st;

    for(int i=0; i<n; i++){

        st.insert(arr[i]);
    }

    int longest = 0;
    int i = 0;

    while(i < n){

        // If exits
        if(st.find(arr[i]-1) == st.end()){

            int val = arr[i];
            int count = 0;

            while(st.find(val) != st.end()){

                val++;
                count++;
            }

            longest = max(count, longest);
        }
        
        i++;
    }

    return longest;
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

    // Longest Consecutive Subsequence
    int longest = longestConsecutiveSubsequence(arr);

    cout << "Longest Subsequence : " << longest;


    cout << endl;
    return 0;
}