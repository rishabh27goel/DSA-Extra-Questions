#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// string findLongestPrefixSuffix(string &str){

//     int n = str.size();

//     for(int len=n-1; len>=0; len--){

//         int i = 0;
//         int j = n - len;

//         bool found = true;

//         while(j < n){

//             if(str[i] != str[j]){

//                 found = false;
//                 break;
//             }

//             i++;
//             j++;
//         }

//         if(found)
//             return str.substr(0, len);
//     }

//     return "";
// }

// Method 2 : Using LPS Array [KMP Algorithm]
// Time Complexity : O(n)  Space Complexity : O(n)
string findLongestPrefixSuffix(string &str){

    int n = str.size();

    vector<int> lps(n, 0);

    int j = 1;
    int len = 0;

    while(j < n){

        if(str[len] == str[j]){

            len++;
            lps[j] = len;
            
            j++;
        }
        else{

            if(len == 0){

                lps[j] = 0;
                j++;
            }
            else{

                len = lps[len-1];
            }
        }
    }

    return str.substr(0, lps[n-1]);
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