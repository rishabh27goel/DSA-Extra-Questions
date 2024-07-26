#include <iostream>
#include <vector>
using namespace std;

// Best Time : O(n)  Space : O(1)
// Average Time : O(n^2)  Space : O(1)
// Worst Time : O(n^2)  Space : O(1)
void insertionSort(vector<int> &arr){

    int n = arr.size();

    for(int i=0; i<n; i++){
        // We will maintain [0 - i] all elements as sorted
        int j = i;
        while(j - 1 >= 0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
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

    insertionSort(arr);

    cout << "Sorted array : ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
