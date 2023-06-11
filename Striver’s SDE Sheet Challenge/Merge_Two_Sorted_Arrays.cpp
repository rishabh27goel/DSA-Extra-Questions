#include <iostream>
#include <vector>
using namespace std;

// Linear Method (Both array)
// Time : O(n + m)  Space : O(1)
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m){

    vector<int> result;
	int i = 0;
	int j = 0;

	while (i < n && j < m) {

		if (arr1[i] <= arr2[j]) {
		
			result.push_back(arr1[i]);
			i++;
		} else {
		
			result.push_back(arr2[j]);
			j++;
		}
	}

	while (i < n) {

		result.push_back(arr1[i]);
		i++;
	}

	while (j < m) {

		result.push_back(arr2[j]);
		j++;
	}

	return result;
}

int main()
{
    cout << "Enter n : ";
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    for(int i=0; i<n1; i++){

        cin >> arr1[i];
    }

    for(int i=0; i<n2; i++){

        cin >> arr2[i];
    }


    vector<int> result = ninjaAndSortedArrays(arr1, arr2, n1, n2);

    cout << "Merged Array : ";

    for(int i=0; i<result.size(); i++){

        cout << result[i] << " ";
    }


    cout << endl;
    return 0;
}