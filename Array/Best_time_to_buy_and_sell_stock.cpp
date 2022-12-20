#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int findMaxProfit(vector<int> &prices){

//     int n = prices.size();

//     int maxProfit = 0;

//     for(int i=0; i<n; i++){

//         for(int j=i+1; j<n; j++){

//             maxProfit = max(prices[j] - prices[i], maxProfit);
//         }
//     }

//     return maxProfit;
// }

// Method 2 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
int findMaxProfit(vector<int> &prices){

    int n = prices.size();

    int maxProfit = 0;
    int maxPrice = INT_MIN;

    for(int i=n-1; i>=0; i--){

        maxPrice = max(prices[i], maxPrice);

        maxProfit = max(maxPrice - prices[i], maxProfit);
    }

    return maxProfit;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i=0; i<n; i++){

        cin >> prices[i];
    }

    // Best Time to Buy and Sell Stock
    int profit = findMaxProfit(prices);

    cout << "Maximum Profit : " << profit;


    cout << endl;
    return 0;
}