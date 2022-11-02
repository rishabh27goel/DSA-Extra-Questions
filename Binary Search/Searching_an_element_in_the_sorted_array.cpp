#include <iostream>
#include <vector>
using namespace std;

// Method : Binary Search [Array should be sorted]
// Time Complexity : O(log(n))  Space Complexity : O(1)
bool searchElement(vector<int> &arr, int target){

    int n = arr.size();

    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(arr[mid] == target){

            return true;
        }
        else if(arr[mid] > target){

            j = mid-1;
        }
        else{

            i = mid+1;
        }

    }

    return false;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter sorted array : ";
    vector <int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    // Search element in the sorted array 
    bool found = searchElement(arr, target);

    if(found){

        cout << "Element Found !!";
    }
    else{

        cout << "Element Not Found !! ";
    }



    cout << endl;
    return 0;
}