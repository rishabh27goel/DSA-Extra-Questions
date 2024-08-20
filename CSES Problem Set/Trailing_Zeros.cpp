#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    int zeroes = 0;
    while(n > 1) {
        n /= 5;
        zeroes += n;
    }
    cout << zeroes << endl;
    
    return 0;
}