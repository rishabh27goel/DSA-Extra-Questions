#include <iostream>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
string findLongestPrefixSuffix(string &str){

    int n = str.size();

    for(int len=n-1; len>=0; len--){

        int i = 0;
        int j = n - len;

        bool found = true;

        while(j < n){

            if(str[i] != str[j]){

                found = false;
                break;
            }

            i++;
            j++;
        }

        if(found)
            return str.substr(0, len);
    }

    return "";
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    string prefix = findLongestPrefixSuffix(input);

    cout << "Prefix String : " << prefix;


    cout << endl;
    return 0;
}