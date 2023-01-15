#include <iostream>
using namespace std;

// Method 1 : Sorting the strings
// Time Complexity : O(n * log(n) + m * log(m))  Space Complexity : O(1)
// bool checkAnagram(string &s1, string &s2){

//     if(s1.size() != s2.size())
//         return false;

//     // Sort the strings
//     sort(s1.begin(), s1.end());
//     sort(s2.begin(), s2.end());


//     for(int i=0; i<s1.size(); i++){

//         if(s1[i] != s2[i])
//             return false;
//     }

//     return true;
// }

// Method 2 : Storing count of chars
// Time Complexity : O(n + m)  Space Complexity : O(26)
bool checkAnagram(string &s1, string &s2){

    if(s1.size() != s2.size())
        return false;

    int charCount[26]= {0};

    for(int i=0; i<s1.size(); i++){

        charCount[s1[i]-'a']++;
    }

    for(int i=0; i<s2.size(); i++){

        if(--charCount[s2[i]-'a'] < 0)
            return false;
    }

    return true;
}

int main()
{
    cout << "Enter First String : ";
    string first;
    cin >> first;

    cout << "Enter Second String : ";
    string second;
    cin >> second;

    // Check for Anagrams
    bool check = checkAnagram(first, second);

    if(check){

        cout << "Both are Anagrams !";
    }
    else{

        cout << "Not Anagrams !";
    }


    cout << endl;
    return 0;
}