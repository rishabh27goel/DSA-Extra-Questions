#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isGoodArray(int size, vector<int> &arr) {
    unordered_map<int, int> freqMap;
    int first = -1;
    int second = -1;
    
    for(int idx = 0; idx < size; idx++) {
        if(first == -1) {
            first = arr[idx];    
        }
        else if(second == -1 && first != arr[idx]) {
            second = arr[idx];
        }
        
        freqMap[arr[idx]]++;
    }
    
    if(freqMap.size() == 1)
        return true;
        
    if(freqMap.size() > 2)
        return false;
        
    return (abs(freqMap[first] - freqMap[second]) <= 1);
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
        
        bool result = isGoodArray(size, arr);
        cout << (result ? "YES" : "NO") << endl;
    }
    
    return 0;
}