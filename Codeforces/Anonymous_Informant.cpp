#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;


        vector<int> arr;
 
        for(int i=0; i<n; i++){

            int data;
            cin >> data;

            arr.push_back(data);
        }

        k = min(n, k);

        bool found = false;
        int last = n-1;

        for(int i=1; i<=k; i++){

            if(arr[last] > n){

                found = true;
                cout << "No" << endl;
                break;   
            }

            last = (last + (n - arr[last])) % n;
        }

        if(found == false)
            cout << "Yes" << endl;
    }

    return 0;
}