#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
int findLargestElement(vector<int> &arr){

    int maxNum = INT_MIN;

    for(int i=0; i<arr.size(); i++){

        maxNum = max(arr[i], maxNum);
    }

    return maxNum;
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

    int largest = findLargestElement(arr);

    cout << "Largest Element is : " << largest;

    cout << endl;
    return 0;
}