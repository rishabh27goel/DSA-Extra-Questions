#include <iostream>
#include <vector>
using namespace std;

// Linear Method
// Time : O(n)  Space : O(1)
void reverseArr(vector<int> &arr, int index){

    if(index == -1)
        return;

    int i = index;
    int j = arr.size()-1;

    while(i <= j){

        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

vector<int> nextPermutation(vector<int> &arr, int n){

    int lastInd = -1;

    for(int i=n-2; i>=0; i--){

        if(arr[i] < arr[i+1]){

            lastInd = i;
            break;
        }
    }

    int swapInd = -1;

    if(lastInd != -1){

        int nextLarger = INT_MAX;

        for(int i=lastInd+1; i<n; i++){

            if(arr[lastInd] < arr[i] && arr[i] < nextLarger){

                nextLarger = arr[i];
                swapInd = i;
            }
        }

        if(swapInd != -1)
            swap(arr[lastInd], arr[swapInd]);
    }

    reverseArr(arr, lastInd+1);    

    return arr;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    vector<int> result = nextPermutation(arr, n);

    cout << "Next Permutation : ";

    for(int i=0; i<n; i++){

        cout << result[i] << " ";
    }


    cout << endl;
    return 0;
}