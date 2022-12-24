#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
void moveZeroesToEnd(vector<int> &arr){

    int n = arr.size();

    int i = 0;
    int j = 0;

    while(i < n){

        if(arr[i] == 0){

            i++;
        }
        else{

            arr[j] = arr[i];
            i++;
            j++;
        }
    }

    for(int i=j; i<n; i++){

        arr[i] = 0;
    }
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


    moveZeroesToEnd(arr);

    cout << "Updated Array : ";
    
    for(int i=0; i<n; i++){

        cout << arr[i] << " ";
    }


    cout << endl;
    return 0;
}