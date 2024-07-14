#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        vector<int> vt = {a, b, c};
        sort(vt.begin(), vt.end());
        
        int times = 5;
        while(times--){
            vt[0]++;
            sort(vt.begin(), vt.end());
        }
        
        cout << vt[0] * vt[1] * vt[2] << endl;
    }
    
    return 0;
}