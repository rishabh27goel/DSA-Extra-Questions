#include <iostream>
using namespace std;

// Recursion
// Time : O(2^n * (log(2^n)))  Space : O(1)
void includeSubset(int n, vector<int> &num, int idx, int sum, vector<int> &result) {

	if (idx == n) {
	
		result.push_back(sum);  
		return;
	}
                

	includeSubset(n, num, idx + 1, sum, result);

	includeSubset(n, num, idx + 1, sum + num[idx], result);
}

vector<int> subsetSum(vector<int> &num){

	int n = num.size();

	vector<int> result;

	includeSubset(n, num, 0, 0, result);

	sort(result.begin(), result.end());

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


    vector<int> result = subsetSum(arr);

    cout << "Subset Sum : ";

    for(int i=0; i<result.size(); i++){

        cout << result[i] << " ";
    }


    cout << endl;
    return 0;
}