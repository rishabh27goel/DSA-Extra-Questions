#include <iostream>
#include <cmath>
using namespace std;

// Method 1 : Recursive Method
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
// void sequence(string &str, int ind, string &seq){

//     if(ind == str.size()){

//         cout << seq << " ";
//         return;
//     }

//     // Exclude
//     sequence(str, ind+1, seq);


//     // Include
//     seq.push_back(str[ind]);
//     sequence(str, ind+1, seq);

//     seq.pop_back();
// }

// void printSubsequence(string &str){

//     string seq = "";

//     sequence(str, 0, seq);
// }

// Method 2 : Iterative Method
// Time Complexity : O(2 ^ n)  Space Complexity : O(n)
void printSubsequence(string &str){

    int n = str.size();
    int power = pow(2, str.size());

    for(int i=0; i<power; i++){

        string seq = "";

        for(int j=0; j<n; j++){

            // If bit is set
            if(i & (1 << j)){

                seq += str[j];
            }
        }

        cout << seq << " ";
    }
}

int main()
{
    string str;
    cin >> str;

    // Print all subsequences of a string
    printSubsequence(str);


    cout << endl;
    return 0;
}