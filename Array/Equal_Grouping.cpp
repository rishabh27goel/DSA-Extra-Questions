#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#include <math.h>

// Link : https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-88/problems/

// Method : Using Stack 
// Time Complexity : O(n)  Space Complexity : O(n)
int findMinSize(vector<int> &arr){

    int n = arr.size();

    for(int i=0; i<n; i++){

        int digits = log10(arr[i]) / log10(2);

        arr[i] = digits;
    }

    stack<int> st;

    for(int i=0; i<n; i++){

        if(st.empty()){

            st.push(arr[i]);
        }
        else{

            if(st.top() == arr[i]){

                st.pop();
            }
            else{

                st.push(arr[i]);
            }
        }
    }

    return st.size();
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

    // Equal Grouping
    int size = findMinSize(arr);

    cout << "Size is : " << size;


    cout << endl;
    return 0;
}