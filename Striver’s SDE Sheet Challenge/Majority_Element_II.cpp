#include <iostream>
#include <vector>
using namespace std;

// Linear Method
// Time : O(n)  Space : O(1)
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> result;

    int n = arr.size();

    int val1 = -1;
    int val2 = -1;

    int c1 = 0;
    int c2 = 0;

    for(int i=0; i<n; i++){

        if(val1 == arr[i]){

            c1++;
        }
        else if(val2 == arr[i]){

            c2++;
        }
        else if(c1 == 0){

            val1 = arr[i];
            c1++;
        }
        else if(c2 == 0){

            val2 = arr[i];
            c2++;
        }
        else{

            c1--;
            c2--;
        }
    }

    c1 = 0;
    c2 = 0;

    for(int i=0; i<n; i++){

        if(val1 == arr[i])
            c1++;
        else if(val2 == arr[i])
            c2++;
    }

    if(c1 > n/3)
        result.push_back(val1);

    if(c2 > n/3)
        result.push_back(val2);

    return result;
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

    vector<int> elements = majorityElementII(arr);


    cout << endl;
    return 0;
}