#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time : O(n ^ 2)  Time : O(n ^ 2)
    // int tupleSameProduct(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     unordered_map<int, int> freqMap;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             int product = nums[i] * nums[j];
    //             freqMap[product]++;
    //         }
    //     }   

    //     int distinct = 0;
    //     for(auto &itr : freqMap) {
    //         if(itr.second > 1) {
    //             int currTotal = ((itr.second * (itr.second - 1)) / 2) * 8;
    //             distinct += currTotal;
    //         }
    //     }

    //     return distinct;
    // }

    int tupleSameProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> sortedProduct;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                sortedProduct.push_back(product);
            }
        }  

        // Sort the product array
        sort(sortedProduct.begin(), sortedProduct.end()); 

        // Finding the frequencies of the elements
        int distinct = 0;
        int j = 0;

        while(j < sortedProduct.size()) {
            int number = sortedProduct[j];
            int count = 0;

            while(j < sortedProduct.size() && number == sortedProduct[j]) {   
                count++, j++;
            }

            if(count > 1) {
                int currTotal = ((count * (count - 1)) / 2) * 8;
                distinct += currTotal;
            }
        }

        return distinct;
    }
};