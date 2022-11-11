#include <iostream>
#include <vector>
using namespace std;

int findXor(int n){

    if(n % 4 == 1){

        return 1;
    }
    else if(n % 4 == 2){

        return n+1;
    }
    else if(n % 4 == 0){

        return n;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n-1);
    int Xor = 0;

    for(int i=0; i<n-1; i++){

        cin >> arr[i];
        Xor ^= arr[i];
    }


    int total = findXor(n);

    cout << (total ^ Xor);

    return 0;
}