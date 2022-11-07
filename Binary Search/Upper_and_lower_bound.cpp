#include <iostream>
#include <vector>
using namespace std;

// Method : Binary Search
int lowerBound(vector<int> &arr, int target){

    int n = arr.size();

    int lower = -1;

    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(arr[mid] <= target){

            lower = arr[mid];
            i = mid + 1;
        }
        else{

            j = mid - 1;
        }
    }

    return lower;
}

int upperBound(vector<int> &arr, int target){

    int n = arr.size();

    int upper = -1;

    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(arr[mid] >= target){

            upper = arr[mid];
            j = mid - 1;
        }
        else{

            i = mid + 1;
        }
    }

    return upper;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);
    cout << "Enter array : ";

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    // Lower Bound
    int lower = lowerBound(arr, target);

    cout << "Lower Bound : " << lower << endl;


    // Upper Bound
    int upper = upperBound(arr, target);

    cout << "Upper Bound : " << upper;


    cout << endl;
    return 0;
}