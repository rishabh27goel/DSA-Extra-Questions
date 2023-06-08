#include <iostream>
#include <vector>
using namespace std;

// Method 1 : 
// Time : O(n)  Space : O(1)
// void sort012(vector<int> &arr, int n){

//     int c1 = 0;
//     int c2 = 0;
//     int c3 = 0;

//     for(int i=0; i<n; i++){

//         if(arr[i] == 0)
//             c1++;
//         else if(arr[i] == 1)
//             c2++;
//         else 
//             c3++;
//     }


//     int i = 0;

//     while(c1--){

//         arr[i++] = 0;
//     }

//     while(c2--){

//         arr[i++] = 1;
//     }

//     while(c3--){

//         arr[i++] = 2;
//     }
// }

// Method 2 : 
// Time : O(n)  Space : O(1)
void sort012(vector<int> &arr, int n){

    int i = 0;
    int j = 0;
    int k = n-1;

    while(j <= k){

        if(arr[j] == 0){

            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if(arr[j] == 1){

            j++;
        }   
        else{

            swap(arr[j], arr[k]);
            k--;
        }
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


    sort012(arr, n);


    cout << "Updated Array : ";

    for(int i=0; i<n; i++){

        cout << arr[i] << " ";
    }


    cout << endl;
    return 0;
}