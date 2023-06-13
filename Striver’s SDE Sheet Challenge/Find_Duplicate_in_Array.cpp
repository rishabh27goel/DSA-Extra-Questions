#include <iostream>
using namespace std;

// Using Map
// Time : O(n)  Space : O(n)
int findDuplicate(vector<int> &arr, int n){
	
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
	
		if(mp.find(arr[i]) != mp.end())
			return arr[i];
	
		mp[arr[i]] = i;
	}

	return -1;
}


// If duplicate is only one
// Space Optimised
// Time : O(n)  Space : O(1)
// int findXor(int n){

//     int mod = n % 4;

//     if(mod == 0)
//         return n;
//     else if(mod == 1)
//         return 1;
//     else if(mod == 2)
//         return n + 1;
//     else
//         return 0;
// }

// int findDuplicate(vector<int> &arr, int n){
	
// 	int xorNum = findXor(n-1);
//     int xorArr = 0;

// 	for(int i=0; i<n; i++){

//         xorArr ^= arr[i];
//     }

// 	return xorArr ^ xorNum;
// }

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;


    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    int duplicate = findDuplicate(arr, n);

    cout << "Duplicate : " << duplicate;


    cout << endl;
    return 0;
}