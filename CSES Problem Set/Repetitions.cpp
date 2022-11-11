#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    
    int maxLen = 0;
    int i = 0;

    while(i < str.size()){

        int length = 0;
        char val = str[i];

        while(i < str.size() && str[i] == val){

            length++;
            i++;
        }

        maxLen = max(length, maxLen);
    }

    cout << maxLen;


    return 0;
}