#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while(t--) {
        int size;
        cin >> size;
        
        int pointX;
        cin >> pointX;
        
        int maxNum = 0; 
        int prevPoint = 0;
        
        for(int idx = 0; idx < size; idx++) {
            int station;
            cin >> station;
            
            maxNum = max(maxNum, station - prevPoint);
            prevPoint = station;
        }
        
        maxNum = max(maxNum, 2 * (pointX - prevPoint));
        cout << maxNum << endl;
    }
    
    return 0;
}