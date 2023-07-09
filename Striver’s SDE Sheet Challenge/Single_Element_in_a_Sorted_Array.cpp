#include <iostream>
using namespace std;

// Method 1 :
// Time : O(n)  Space : O(1)
// int singleNonDuplicate(vector<int>& arr)
// {
//     int n = arr.size();

//     int xorNum = 0;

//     for (int i = 0; i < n; i++) {
        
//         xorNum ^= arr[i];
//     }

//     return xorNum;
// }

// Method 2 :
// Time : O(log(n))  Space : O(1)
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();

	int i = 0;
	int j = n-1;

	while(i < j){

		int mid = i + (j - i + 1) / 2;

		if(arr[mid] == arr[mid-1]){

			if(mid % 2 == 0){

				j = mid;
			}
			else{

				i = mid+1;
			}
		}
		else{

			if(mid % 2 == 0){

				i = mid;
			}
			else{

				j = mid-1;
			}
		}
	}

	return arr[i];
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


    int single = singleNonDuplicate(arr);

    cout << "Single Element : " << single;


    cout << endl;
    return 0;
}