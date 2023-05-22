#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute Force
// Time : O(n)  Space : O(1)
// vector<int> nextGreaterElement(vector<int> &arr){

//     int n = arr.size();

//     vector<int> result;

//     for(int i=0; i<n; i++){

//         int greater = -1;

//         for(int j=i+1; j<n; j++){

//             if(arr[j] > arr[i]){

//                 greater = arr[j];
//                 break;
//             }
//         }

//         result.push_back(greater);
//     }

//     return result;
// }

// Using Stack
// Time : O(n)  Space : O(n)
vector<int> nextGreaterElement(vector<int> &arr){

    int n = arr.size();

    vector<int> result(n);
    stack<int> st;

    for(int i=n-1; i>=0; i--){

        // Remove the elements
        while(!st.empty() && st.top() <= arr[i]){

            st.pop();
        }


        if(st.empty()){

            result[i] = -1;
        }
        else{

            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    return result;
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

    vector<int> greater = nextGreaterElement(arr);


    cout << "Greater element array : ";

    for(int i=0; i<n; i++){

        cout << greater[i] << " ";
    }


    cout << endl;
    return 0;
}