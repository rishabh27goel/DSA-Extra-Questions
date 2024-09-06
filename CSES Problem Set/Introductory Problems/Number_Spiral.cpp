#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;

    while(t--) {
        ll x, y;
        cin >> x >> y;

        ll maxNum = max(x, y);
        ll start = ((maxNum - 1) * (maxNum - 1));
        ll end = maxNum * maxNum;
    
        if(maxNum % 2 == 0) {    
            if(y == maxNum) {
                cout << start + x << endl;
            }
            else {
                cout << end - (y - 1) << endl;
            }
        }
        else {
            if(x == maxNum) {
                cout << start + y << endl;
            }
            else {
                cout << end - (x - 1) << endl;
            }
        }
    }


    return 0;
}