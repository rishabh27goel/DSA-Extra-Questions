#include <iostream>
#include <vector>
using namespace std;

// Linear Method (Greedy)
// Time : O(n)  Space : O(1)
int maximumProfit(vector<int> &prices){

    int n = prices.size();


    int maxProfit = 0;
    int minVal = prices[0];

    for(int i=1; i<n; i++){

        maxProfit = max(maxProfit, prices[i] - minVal);
        minVal = min(minVal, prices[i]);
    }

    return maxProfit;
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


    int maxProfit = maximumProfit(arr);

    cout << "Max Profit : " << maxProfit;


    cout << endl;
    return 0;
}