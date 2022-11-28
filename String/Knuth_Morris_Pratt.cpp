#include <iostream>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * p)  Space Complexity : O(1)
bool searchPattern(string &input, string &pattern){

    int n = input.size();
    int p = pattern.size();

    for(int i=0; i<n; i++){

        int j = 0;

        while(j < p){

            if(input[i+j] != pattern[j])
                break;

            j++;
        }

        if(j == p)
            return true;
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