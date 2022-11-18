#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(2 ^ n)  Space Complexity : O(2 ^ n)
vector<string> findGrayCode(int n){

    vector<string> gray(1, "");

    while(n--){

        int size = gray.size();

        for(int i=size-1; i>=0; i--){

            gray.push_back(gray[i]);
        }

        for(int i=0; i<size; i++){

            gray[i] = '0' + gray[i];
        }

        for(int i=size; i<2*size; i++){

            gray[i] = '1' + gray[i];
        }
    }

    return gray;
}

int main()
{
    int n;
    cin >> n;

    vector<string> gray = findGrayCode(n);

    for(int i=0; i<gray.size(); i++){

        cout << gray[i] << endl;
    }

    cout << endl;
    return 0;
}