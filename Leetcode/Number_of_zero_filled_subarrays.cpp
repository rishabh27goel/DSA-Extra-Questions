#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
int numberOfSubarrays(vector<int> &arr){

    int n = arr.size();

    int result = 0;
    int j = 0;

    while(j < n){

        if(arr[j] == 0){

            int c = 0;

            while(j < n && arr[j] == 0){

                c++;
                result += c;
                j++;
            }
        }
        else{

            j++;
        }
    }

    return result;
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


    // Number of Zero-Filled Subarrays
    int count = numberOfSubarrays(arr);

    cout << "Subarray Count : " << count;


    cout << endl;
    return 0;
}