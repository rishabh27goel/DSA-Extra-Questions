#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method : Using Stack [Next Smaller Element]
// Time Complexity : O(n)  Space Complexity : O(n)
vector<int> finalPrices(vector<int> &arr){

    int n = arr.size();

    stack<int> st;

    for(int i=n-1; i>=0; i--){

        int val = arr[i];

        while(!st.empty() && st.top() > arr[i]){

            st.pop();
        }

        if(!st.empty()){

            arr[i] -= st.top();
        }

        st.push(val);
    }

    return arr;
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

    // Final Prices With a Special Discount in a Shop
    vector<int> result = finalPrices(arr);


    cout << "Final Prices : ";

    for(int i=0; i<result.size(); i++){

        cout << result[i] << " ";
    }


    cout << endl;
    return 0;
}