#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int num;
        cin >> num;
        
        cout << (num % 3 == 0 ? "Second" : "First") << endl;
    }
    
    return 0;
}