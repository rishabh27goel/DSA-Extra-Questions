#include <iostream>
#include <vector>
using namespace std;

// Using Unordered Map
// Time : O(n)  Space : O(n)
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();

    int result = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefix = 0;

    for(int i=0; i<n; i++){

        prefix ^= arr[i];

        if(mp.find(prefix ^ x) != mp.end())
            result += mp[prefix ^ x];

        mp[prefix]++;
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

    cout << "Enter k : ";
    int k;
    cin >> k;


    int total = subarraysXor(arr, k);

    cout << "Total Subarrays : " << total;

    cout << endl;
    return 0;
}