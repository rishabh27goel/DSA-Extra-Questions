#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// bool isPalindrome(string &str, int i, int j){

//     while(i <= j){

//         if(str[i] != str[j]){

//             return false;    
//         }

//         i++;
//         j--;
//     }

//     return true;
// }

// int findMinimumCharacters(string &str){

//     int n = str.size();

//     int minCount = INT_MAX;

//     int i = 0;
//     int j = n-1;

//     while(i <= j){

//         if(isPalindrome(str, i, j)){

//             break;
//         }
//         else{

//             j--;
//         }
//     }

//     return (n - (j - i + 1));
// }

// Method 2 : KMP Algorithm & LPS Array
// Time Complexity : O(n)  Space Complexity : O(n)
void createLPS(string &str, vector<int> &lps){

    int n = str.size();

    int j = 1;
    int len = 0;

    while(j < n){

        if(str[j] == str[len]){

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
}

int findMinimumCharacters(string &str){

    int n = str.size();

    string newStr = str + "$";
    reverse(str.begin(), str.end());
    newStr += str;

    // Create LPS Array
    vector<int> lps(newStr.size(), 0);

    createLPS(newStr, lps);

    return n - lps[newStr.size()-1];
}

int main()
{
    cout << "Enter Input String : ";
    string str;
    cin >> str;

    int count = findMinimumCharacters(str);

    cout << "Minimum Characters : " << count;


    cout << endl;
    return 0;
}