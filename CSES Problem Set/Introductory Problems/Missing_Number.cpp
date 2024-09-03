#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findMissingNumber(vector<int> &arr) {
    int n = arr.size();

    unordered_set<int> st;
    for(int j = 0; j < n; j++) {
        st.insert(arr[j]);
    }

    for(int j = 1; j <= n + 1; j++) {
        if(st.find(j) == st.end())
            return j;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for(int j = 0; j < n - 1; j++) {
        cin >> arr[j];
    }

    int missing = findMissingNumber(arr);
    cout << missing;

    return 0;
}