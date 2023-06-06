#include <iostream>
using namespace std;

#define ll long long int

// Brute Force
// Time : O(n * n)  Space : O(n * n)
// vector< vector<ll> > printPascal(int n) {

//     vector< vector<ll> > result;

//     for(int i=0; i<n; i++){

//         vector<ll> level;

//         level.push_back(1);

//         for(int j=1; j<i; j++){

//             level.push_back(result[i-1][j-1] + result[i-1][j]);
//         }   

//         if(i > 0)
//             level.push_back(1);

//         result.push_back(level);
//     }

//     return result;
// }

// Another Method
// Time : O(n * n)  Space : O(n * n)
vector< vector<ll> > printPascal(int n) {

    vector< vector<ll> > result;

    for(int i=1; i<=n; i++){

        vector<ll> level;

        ll c = 1;

        for(int j=1; j<=i; j++){

            level.push_back(c);

            c *= (i - j);
            c /= j;
        }

        result.push_back(level);
    }

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector< vector<ll> > triangle = printPascal(n);

    cout << "Pascal's Triangle : \n";

    for(int i=0; i<triangle.size(); i++){

        for(int j=0; j<triangle[i].size(); j++){

            cout << triangle[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}