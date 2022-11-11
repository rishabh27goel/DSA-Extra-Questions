#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    
    unordered_map<int, int> store;

    for(int i=0; i<n; i++){

        store[arr[i]] = i+1;
    }

    int rounds = 1;
    int i = 2;
    int start = store[1];

    while(i <= n){

        if(store[i] < start)
            rounds++;

        start = store[i];
        i++;
    }

    cout << rounds;

    return 0;
}