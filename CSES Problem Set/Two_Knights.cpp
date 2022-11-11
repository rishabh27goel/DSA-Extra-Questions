#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;


    for(int i=1; i<=n; i++){

        if(i == 1){

            cout << "0" << endl;
        }
        else{

            long k1 = i * i;
            long k2 = k1 - 1;

            cout << ((k1 * k2) >> 1) - (4 * (i-1) * (i-2)) << endl;
        }
    }



    return 0;
}