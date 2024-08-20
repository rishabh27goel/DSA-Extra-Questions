#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 1) {
        cout << 1 << endl;
    }
    else if(n <= 3) {
        cout << "NO SOLUTION";
    }
    else {
        vector<int> arr(n);
        int counter = 1;

        int start = 1;
        while(start < n) {
            arr[start] = counter++;
            start += 2;
        }

        start = 0;
        while(start < n) {
            arr[start] = counter++;
            start += 2;
        }

        for(int i=0; i<n; i++) {
            cout << arr[i] << " "; 
        }
    }


    return 0;
}