#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr, int n, int val) {
	
	sort(arr.begin(), arr.end());

	vector<vector<int>> result;

	int k = 0;

	while(k < n){
	
		int target = val - arr[k];

		int i = k+1;
		int j = n-1;

		while(i < j){

			if(arr[i] + arr[j] == target){

				result.push_back({arr[k], arr[i], arr[j]});

				int start = arr[i];

				while(i < n && start == arr[i])
					i++;


				int end = arr[j];

				while(i < n && end == arr[j])
					j--;
			}
			else if(arr[i] + arr[j] > target){

				j--;
			}
			else{

				i++;
			}
		}

		int num = arr[k];

		while(k < n && num == arr[k])
			k++;
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

	cout << "Enter target : ";
	int target;
	cin >> target;


	vector< vector<int> > result = findTriplets(arr, n, target);
    


    cout << endl;
    return 0;
}