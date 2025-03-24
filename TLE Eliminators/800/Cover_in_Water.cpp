#include <iostream>
#include <vector>
using namespace std;

/*
    We have to observe if we have a chain of '.' having length 
    more than 2 then we can create any number of water cells 
    using operation 2
*/

int getMinimumOperations(int size, string &str) {
    int operations = 0;
    int idx = 0;
    
    while(idx < size) {
        if(str[idx] == '#') {
            idx++;
        }
        else {
            int count = 0;
            while(idx < size && str[idx] == '.') {
                count++, idx++;
            }
            
            if(count >= 3)  return 2;
            operations += count;
        }
    }
    return operations;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int size;
        cin >> size;
        
        string str;
        cin >> str;
        
        cout << getMinimumOperations(size, str) << endl;
    }
    
    return 0;
}