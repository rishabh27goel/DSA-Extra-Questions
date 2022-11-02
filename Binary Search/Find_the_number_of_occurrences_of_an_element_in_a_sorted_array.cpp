#include <iostream>
#include <vector>
using namespace std;

// Method : Binary Search
// Time Complexity : O(log(n))  Space Complexity : O(1)
int numberOfOccurrences(vector<int> &arr, int target){

    int n = arr.size();

    // First Occurrence
    int first = -1;

    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(arr[mid] == target)
            first = mid;


        if(arr[mid] >= target){

            j = mid - 1;
        }
        else{

            i = mid + 1;
        }
    }

    // Last Occurrence
    int last = -1;

    i = 0;
    j = n-1;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(arr[mid] == target)
            last = mid;


        if(arr[mid] <= target){

            i = mid + 1;
        }
        else{

            j = mid - 1;
        }
    }


    if(first == -1 && last == -1)
        return 0;


    return (last - first) + 1;
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


    // Number of Occurrences
    int count = numberOfOccurrences(arr, target);

    cout << "Number of occurrences : " << count;


    cout << endl;
    return 0;
}