#include <iostream>
#include <vector>
using namespace std;

/*
    Case 1: If array is sorted  -> YES
    Case 2 : If array in non sorted 
        1. If window size is more than 1 then it is 
        always possible to sort the array (k > 1)
        2. Not possible if k == 1
*/

bool isSortedArray(vector<int> &arr) {
    int prevNum = INT_MIN;
    for(auto num : arr) {
        if(prevNum > num)
            return false;
            
        prevNum = num;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int size;
        cin >> size;
        
        int window;
        cin >> window;
        
        vector<int> arr(size);
        for(int idx = 0; idx < size; idx++) {
            cin >> arr[idx];
        }
        
        if(isSortedArray(arr) || window > 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    
    return 0;
}