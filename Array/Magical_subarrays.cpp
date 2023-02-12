#include <iostream>
#include <vector>
using namespace std;

// Method : Using Two Pointer
// Time Complexity : O(n)  Space Complexity : O(1)
int countSubarrays(vector<int> &arr){

    int n = arr.size();

    int result = 0;

    int j = 0;
    int cnt = 0;
    int c = 0;

    for(int i=0; i<n; i++){

        if(arr[i] % 2 == 1){

            arr[i] = 1;
            j = i + 1; 
            c++;   
        }
        else{

            cnt += (i - j + 1);
            arr[i] = 0;
        }
    }

    if(c == 0)
        return 0;

    int sum = 0;
    int x0 = 1;
    int x1 = 0;

    for(int i=0; i<n; i++){

        sum += arr[i];
        sum %= 2;

        sum == 0 ? ++x0 : ++x1;
    }

    return (x1 * (x1-1) / 2) + (x0 * (x0-1) / 2) - cnt;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter array : ";
    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    int count = countSubarrays(arr);

    cout << "Subarray Count : " << count;


    cout << endl;
    return 0;
}