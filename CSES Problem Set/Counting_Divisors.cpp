#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        if(n == 1){

            cout << n << endl;
            continue;
        }

        int divisor = 0;
        int root = sqrt(n);


        for(int i=1; i<=(int) root; i++){

            if(n % i == 0){

                if(i * i == n)
                    divisor += 1;
                else
                    divisor += 2;
            }
        }

        cout << divisor << endl;
    }


    cout << endl;
    return 0;
}