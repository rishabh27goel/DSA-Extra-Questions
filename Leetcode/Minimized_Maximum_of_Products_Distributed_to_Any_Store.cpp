#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long isValidProduct(int size, vector<int> &quantities, int maxNum) {
        int q = quantities.size();

        long currSize = 0;
        for(int j = 0; j < q; j++) {
            currSize += (int) ceil((double) quantities[j] / maxNum);
            if(currSize > size)
                return false;
        }
        return true;
    }

    int minimizedMaximum(long n, vector<int>& quantities) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int q = quantities.size();

        int start = 1;
        int end = 1e5;

        int minX = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(isValidProduct(n, quantities, mid)) {
                minX = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return minX;
    }
};