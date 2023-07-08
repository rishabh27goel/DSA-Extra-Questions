#include <iostream>
using namespace std;

// Linear Method
// Time : O(n)  Space : O(1)
int removeDuplicates(vector<int> &arr, int n) {
	
	int c = 0;
	int i = 0;

	while(i < n){

		int val = arr[i];

		while(i < n && val == arr[i]){

			i++;
		}

		c++;
	}

	return c;
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


    int length = removeDuplicates(arr, n);

    cout << "Length is : " << length;


    cout << endl;
    return 0;
}