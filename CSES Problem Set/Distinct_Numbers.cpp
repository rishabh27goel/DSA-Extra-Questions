#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Distinct Numbers
    set<int> st;

    for(int i=0; i<n; i++){

        st.insert(arr[i]);
    }

    cout << st.size();

    return 0;
}