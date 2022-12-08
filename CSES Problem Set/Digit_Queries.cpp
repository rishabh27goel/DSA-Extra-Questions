#include <iostream>
using namespace std;

#define ll long long int

ll findDigit(ll n){

    if(n <= 9)
        return n;

    ll count = 1;
    ll multipler = 9;
    ll sum = 0;
    
    while(n >= count * multipler){

        n -= (count * multipler);

        sum += multipler;
        count++;
        multipler *= 10;
    }

    ll number = n / count;
    ll mod = n % count;

    if(mod == 0){

        number--;
        mod = count;
    }

    mod = count + 1 - mod;
    number += (sum + 1);

    ll digit = -1;

    while(mod--){

        digit = number % 10;
        number /= 10;
    }

    return digit;
}

int main()
{
    ll n;
    cin >> n;

    while(n--){

        ll k;
        cin >> k;

        ll digit = findDigit(k);

        cout << digit << endl;
    }


    cout << endl;
    return 0;
}