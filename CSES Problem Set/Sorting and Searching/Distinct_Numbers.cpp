#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDistinctNumbers(vector<int> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int distinct = 0;
    int j = 0;

    while(j < n) {
        int val = arr[j];
        while(j < n && val == arr[j]) {
            j++;
        }
        distinct++;
    }

    return distinct;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinct = findDistinctNumbers(arr);
    cout << distinct;

    return 0;
}