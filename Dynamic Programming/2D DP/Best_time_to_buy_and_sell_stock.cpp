#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method 1 : Buying at each index
// Time Complexity : O(n^2)  Space Complexity : O(1)
// int findPrice(vector<int> &prices){

//     int n = prices.size();

//     int maxProfit = 0;

//     // Buying at ith index and selling at jth index
//     for(int i=0; i<n; i++){

//         for(int j=i+1; j<n; j++){

//             maxProfit = max(prices[j]-prices[i], maxProfit);
//         }
//     }

//     return maxProfit;
// }

// Method 2 : Selling stock at each index
// Time Complexity : O(n)  Space Complexity : O(1)
int findPrice(vector<int> &prices){

    int n = prices.size();

    // Keeping track of minimum stocks
    int maxProfit = 0;
    int minStock = prices[0];

    // Buying at ith index and selling at jth index
    for(int i=1; i<n; i++){

        maxProfit = max(prices[i]-minStock, maxProfit);
        minStock = min(prices[i], minStock);
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

    // Best time to buy and sell stock
    int profit = findPrice(prices);

    cout << "Maximum Profit : " << profit;

    cout << endl;
    return 0;
}