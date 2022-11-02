#include <iostream>
#include <vector>
using namespace std;

// Method : Binary Search
// Time Complexity : O(log(n))  Space Complexity : O(1)
int findFirstPosition(vector<int> &arr, int target){

    int n = arr.size();

    // For getting first occurence
    int first = -1;

    int i = 0;
    int j = n-1;

    while(i <= j){

        // For getting the middle index
        int mid = i + (j - i) / 2;


        // If we find the target
        if(arr[mid] == target)
            first = mid;

        // For finding the first occurence we will search left side 
        // in { arr[mid] == target } case
        if(arr[mid] >= target){

            j = mid - 1;
        }
        else{

            i = mid + 1;
        }
    }

    return first;
}

int findLastPosition(vector<int> &arr, int target){

    int n = arr.size();

    // For getting last occurence
    int last = -1;

    int i = 0;
    int j = n-1;

    while(i <= j){

        // For getting the middle index
        int mid = i + (j - i) / 2;


        // If we find the target
        if(arr[mid] == target)
            last = mid;

        // For finding the last occurence we will search right side 
        // in { arr[mid] == target } case
        if(arr[mid] <= target){

            i = mid + 1;
        }
        else{

            j = mid - 1;
        }
    }

    return last;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";
    vector <int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    // First and last position of an element
    int first = findFirstPosition(arr, target);

    cout << "First Occurence : " << first << endl;


    int last = findLastPosition(arr, target);

    cout << "Last Occurence : " << last << endl;


    cout << endl;
    return 0;
}