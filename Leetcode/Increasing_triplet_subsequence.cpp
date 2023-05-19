#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter array size : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    cout << endl;
    return 0;
}