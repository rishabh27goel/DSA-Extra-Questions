#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin >> n;

    vector< pair<ll, ll> > points;

    for(ll i=0; i<n; i++){

        ll a, b;
        cin >> a >> b;

        points.push_back(make_pair(a, b));
    }

    // Polygon Area
    ll half1 = 0;
    ll half2 = 0;
    
    for(ll i=0; i<n; i++){

        half1 += (points[i].first * points[(i + 1) % n].second);
        half2 += (points[(i + 1) % n].first * points[i].second);
    }

    cout << abs((half1 - half2));


    cout << endl;
    return 0;
}