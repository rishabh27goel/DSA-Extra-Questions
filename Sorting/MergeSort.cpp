#include <iostream>
#include <vector>
using namespace std;

// Best Time : O(n * log(n))  Space : O(n)
// Average Time : O(n * log(n))  Space : O(n)
// Worst Time : O(n * log(n))  Space : O(n)
void mergeStep(vector<int> &arr, int start, int middle, int end){

    vector<int> mergedArr;
    int i = start;
    int j = middle + 1;

    while(i <= middle && j <= end){
        if(arr[i] <= arr[j]){
            mergedArr.push_back(arr[i]);
            i++;
        }
        else{
            mergedArr.push_back(arr[j]);
            j++;
        }
    }

    while(i <= middle){
        mergedArr.push_back(arr[i]);
        i++;   
    }

    while(j <= end){
        mergedArr.push_back(arr[j]);
        j++;
    }

    for(int j=start; j <= end; j++){
        arr[j] = mergedArr[j-start]; 
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    
    // Base Case
    if(start == end)  return;

    // Divide step
    int middle = start + (end - start) / 2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);

    // Merge step
    mergeStep(arr, start, middle, end);
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

    mergeSort(arr, 0, n-1);

    cout << "Sorted array : ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
