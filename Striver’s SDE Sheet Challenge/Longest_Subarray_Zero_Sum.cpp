#include <iostream>
#include <vector>
using namespace std;

// Using unordered map
// Time : O(n)  Space : O(n)
int longestSubsetWithZeroSum(vector<int> &arr) {

  int n = arr.size();

  int result = 0;

  unordered_map<int, int> mp;
  int prefix = 0;
  
  mp[0] = -1; 

  for(int i=0; i<n; i++){

    prefix += arr[i];

    if(mp.find(prefix) != mp.end())
      result = max(result, i - mp[prefix]);
    else
      mp[prefix] = i;
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


    int length = longestSubsetWithZeroSum(arr);

    cout << "Longest Subarray : " << length;


    cout << endl;
    return 0;
}