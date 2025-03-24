#include <iostream>
#include <vector>
using namespace std;
 
// Method 1 :
// bool isArraySorted(int size, vector<int> &arr) {
//     for(int idx = 0; idx < size; idx++) {
//         if(idx + 1 != arr[idx])
//             return false;
//     }
//     return true;
// }
 
// bool isValid(int size, vector<int> &arr) {
//     bool swapMade = true;
//     while(swapMade) {
//         swapMade = false;
//         for(int idx = 1; idx < size - 1; idx++) {
//             if(arr[idx - 1] < arr[idx] && arr[idx] > arr[idx + 1]) {
//                 swap(arr[idx], arr[idx + 1]);
//                 swapMade = true;
//             }
//         }
//     }
    
//     if(isArraySorted(size, arr))
//         return true;
 
//     return false;
// }
 
// Method 2 : 
// This one is a tricky solution 
// If we see any permutation is valid if the smallest number is at the start
// Smallest number is 1 here
bool isValid(int size, vector<int> &arr) {
    if(arr[0] == 1)
        return true;
        
    return false;
}
 
int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int size;
        cin >> size;
        
        vector<int> arr(size);
        for(int idx = 0; idx < size; idx++) {
            cin >> arr[idx];
        }
        
        bool result = isValid(size, arr);
        cout << (result ? "YES" : "NO") << endl;
    }
    
    return 0;
}