#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
vector<int> findOriginalArray(vector<int> &arr){

    int n = arr.size();

    int prev = arr[0];

    for(int i=1; i<n; i++){

        int store = arr[i];

        arr[i] = (arr[i] ^ prev);
        prev = store;
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

    vector<int> result = findOriginalArray(arr);

    cout << "Original Array : ";
    
    for(int i=0; i<result.size(); i++){

        cout << result[i] << " ";
    }



    cout << endl;
    return 0;
}