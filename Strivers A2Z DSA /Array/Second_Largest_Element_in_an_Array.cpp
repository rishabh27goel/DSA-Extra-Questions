#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
int findSecondLargest(vector<int> &arr){

    int first = INT_MIN;
    int second = INT_MIN;

    for(int i=0; i<arr.size(); i++){

        if(first < arr[i]){

            second = first;
            first = arr[i];
        }
        else if(second < arr[i]){

            second = arr[i];
        }
    }

    return second;
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

    int secondLargest = findSecondLargest(arr);

    cout << "Second Largest is : " << secondLargest;


    cout << endl;
    return 0;
}