#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method 
// Time Complexity : O(n)  Space Complexity : O(1)
bool canPlaceFlower(vector<int> &arr, int k){

    int n = arr.size();

    int j = 0;

    while(j < n){

        // If current value is 0
        if(arr[j] == 0){

            // If prev value is possible
            if(j == 0 || arr[j-1] == 0){

                if(j + 1 == n || arr[j+1] == 0){

                    arr[j] = 1;
                    k--;
                }
            }
        }

        j++;
    }

    return k <= 0;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter k : ";
    int k;
    cin >> k;


    // Can Place Flowers
    bool check = canPlaceFlower(arr, k);

    if(check){

        cout << "Can Place !!";
    }
    else{

        cout << "Can Not Place !!";
    }


    cout << endl;
    return 0;
}