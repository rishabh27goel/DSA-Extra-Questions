#include <iostream>
#include <vector>
using namespace std;

// Time : O(n^2)  Space : O(1)
void selectionSort(vector<int> &arr){

    int n = arr.size();

    for(int i=0; i<n; i++){
        int smallest = i;
        for(int j=i; j<n; j++){
            if(arr[smallest] > arr[j]){
                smallest = j;
            }
        }
        swap(arr[smallest], arr[i]);
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

    selectionSort(arr);

    cout << "Sorted array : ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
