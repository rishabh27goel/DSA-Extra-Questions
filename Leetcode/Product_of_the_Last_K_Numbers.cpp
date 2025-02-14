#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    // The problem was simple if there was no zero in the array
    // But the trick to this question is as we are moving with stream we only
    // track elements after a zero has occured
    vector<int> streamProduct;
    int runningProduct = 1;

    ProductOfNumbers() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        // This is important to handle the window
        // Ex -> 1 2 3 4 5 -> 1 2 6 24 120
        // k -> 5
        // runningProduct -> 1 1 2 6 24 120 -> 120 (last index) / 1 (first index)
        streamProduct = {1};
    }

    void add(int num) {
        if (num == 0) {
            streamProduct = {1};
            runningProduct = 1;
        } 
        else {
            runningProduct *= num;
            streamProduct.push_back(runningProduct);
        }
    }

    int getProduct(int k) {
        int size = streamProduct.size();
        int streamIdx = (size - k - 1);

        if(streamIdx < 0)
            return 0;

        return streamProduct[size-1] / streamProduct[streamIdx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */