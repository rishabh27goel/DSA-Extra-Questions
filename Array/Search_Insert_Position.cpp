#include <iostream>
#include <vector>
using namespace std;

// Method : Using Binary Search 
// Time Complexity : O(log(n))  Space Complexity : O(1)
int findInsertPosition(vector<int> &arr, int target){

    int n = arr.size();

    int index = n;
    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = (i + j) / 2;

        if(arr[mid] == target){

            return mid;
        }
        else if(arr[mid] > target){

            index = mid;
            j = mid-1;
        }
        else{

            i = mid+1;
        }
    }

    return index;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";

    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    int pos = findInsertPosition(arr, target);

    cout << "Position is : " << pos;


    cout << endl;
    return 0;
}