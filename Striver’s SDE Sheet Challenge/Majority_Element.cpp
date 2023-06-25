#include <iostream>
using namespace std;

// Linear Method
// Time : O(n)  Space : O(1)
int findMajorityElement(vector<int> &arr, int n) {
	
	int majority = arr[0];
	int c = 1;

	for(int i=1; i<n; i++){

		if(majority == arr[i]){

			c++;
		}
		else{

			c--;

			if(c < 0){

				majority = arr[i];
				c = 1;
			}
		}
	}

	c = 0;

	for(int i=0; i<n; i++){

		if(arr[i] == majority)
			c++;
	}

	return (c > n/2 ? majority : -1);
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


    int majority = findMajorityElement(arr, n);

    cout << "Majority Element : " << majority;


    cout << endl;
    return 0;
}