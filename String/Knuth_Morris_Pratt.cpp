#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * p)  Space Complexity : O(1)
// bool searchPattern(string &input, string &pattern){

//     int n = input.size();
//     int p = pattern.size();

//     for(int i=0; i<n; i++){

//         int j = 0;

//         while(j < p){

//             if(input[i+j] != pattern[j])
//                 break;

//             j++;
//         }

//         if(j == p)
//             return true;
//     }

//     return false;
// }

// Method 2 : KMP Algorithm
// Time Complexity : O(n * p)  Space Complexity : O(1)
vector<int> computeLPS(string &pattern){

    int m = pattern.size();

    // Initialize LPS
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while(i < m){

        if(pattern[len] == pattern[i]){

            len++;
            lps[i] = len;
            
            i++;
        }
        else{

            // If length is not zero then check previous
            if(len != 0){

                len = lps[len-1];
            }
            else{

                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool searchPattern(string &input, string &pattern){

    int n = input.size();
    int m = pattern.size();

    // Create LPS Array [ Longest Prefix Suffix ]
    vector<int> lps = computeLPS(pattern);


    // Search pattern in input string
    int i = 0;
    int j = 0;

    while(i < n - m + 1){

        // If match is found
        if(input[i] == pattern[j]){

            i++;
            j++;
        }
        else{

            if(j != 0){

                j = lps[j-1];
            }
            else{

                i++;
            }
        }
        
        if(j == m){

            cout << "Match Found at index " << i - j << endl;
            j = lps[j-1];
        }
    }

    return false;
}

int main()
{
    cout << "Enter input string : ";
    string input;
    cin >> input;

    cout << "Enter pattern string : ";
    string pattern;
    cin >> pattern;

    // Searching a pattern in input string
    bool found = searchPattern(input, pattern);

    if(found){

        cout << "Pattern found !!";
    }
    else{

        cout << "Pattern not found !!";
    }

    return 0;
}