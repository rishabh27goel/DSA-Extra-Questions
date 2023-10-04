#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;


        bool found = false;

        for(int i=0; i<n; i++){

            int data;
            cin >> data;

            if(data == k){

                found = true;
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }   


    return 0;
}