#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(2 ^ n)  Space Complexity : O(2 ^ n)
vector<int> findGrayCode(int n){

    vector<int> gray;

    for(int i = 0; i < (1 << n); i++){

        gray.push_back(i ^ (i >> 1));
    }

    return gray;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> gray = findGrayCode(n);
    cout << "Gray Code (n-bit): ";

    for(int i=0; i<gray.size(); i++){

        cout << gray[i] << " ";
    }

    cout << endl;
    return 0;
}