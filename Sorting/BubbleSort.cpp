#include <iostream>
#include <vector>
using namespace std;

// Time : O(n^2)  Space : O(1)
// void bubbleSort(vector<int> &arr){

//     int n = arr.size();

//     for(int i=n-1; i>=0; i--){
//         for(int j=0; j<i; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

// Optimise bubble sort 
// If no swap was there it means the array was already sorted
void bubbleSort(vector<int> &arr){

    int n = arr.size();

    for(int i=n-1; i>=0; i--){
        bool didSwap = true;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = false;
            }
        }

        // Array is already sorted
        if(didSwap)
            break;
    }
}

int main() 
{
    cout << "Enter size of the array : ";
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubbleSort(arr);

    cout << "Sorted array : ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
