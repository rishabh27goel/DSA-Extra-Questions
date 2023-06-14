#include <iostream>
#include <vector>
using namespace std;

// Using Bit Mask
// Time : O((2 ^ n) * n)  Space : O(1)
vector< vector<int> > pwset(vector<int> &v)
{
    int n = v.size();

    vector< vector<int> > result;
    int p = pow(2, n);

    for(int i=0; i<p; i++){

        vector<int> sub;

        for(int j=0; j<n; j++){

            if(i & (1 << j)){

                sub.push_back(v[j]);
            }
        }

        result.push_back(sub);
    }

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    vector< vector<int> > result = pwset(arr);
    
    cout << "Power Set : \n";

    for(int i=0; i<result.size(); i++){

        for(int j=0; j<result[i].size(); j++){

            cout << result[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}