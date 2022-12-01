#include <iostream>
#include <unordered_map>
using namespace std;

// Method 1 : Sorting the strings
// Time Complexity : O(n * log(n) + m1 * log(m1) + m2 * log(m2))   Space Complexity : O(1)
// bool checkShuffle(string &input, string &str1, string &str2){

//     if(str1.size() + str2.size() != input.size())
//         return false;

//     // Sort all the strings 
//     sort(input.begin(), input.end());
//     sort(str1.begin(), str1.end());
//     sort(str2.begin(), str2.end());


//     int k = 0;
//     int i = 0;
//     int j = 0;

//     while(i < str1.size() && j < str2.size()){

//         if(input[k] == str1[i]){

//             i++;
//             k++;
//         }
//         else if(input[k] == str2[j]){

//             j++;
//             k++;
//         }
//         else{

//             return false;
//         }
//     }

//     while(i < str1.size()){

//         if(input[k] != str1[i]){

//             return false;
//         }

//         i++;
//         k++;
//     }

//     while(j < str2.size()){

//         if(input[k] != str2[j]){

//             return false;
//         }

//         j++;
//         k++;
//     }

//     return true;
// }

// Method 2 : Checking the count of strings
// Time Complexity : O(n + m1 + m2)   Space Complexity : O(2 * (distinct characters))
bool checkShuffle(string &input, string &str1, string &str2){

    if(str1.size() + str2.size() != input.size())
        return false;

    
    unordered_map<char, int> inputCount;
    unordered_map<char, int> subCount;
    
    for(int i=0; i<input.size(); i++){

        inputCount[input[i]]++;
    }

    for(int i=0; i<str1.size(); i++){

        subCount[str1[i]]++;
    }

    for(int i=0; i<str2.size(); i++){

        subCount[str2[i]]++;
    }

    // Checking Count
    for(int i=0; i<input.size(); i++){

        if(inputCount[input[i]] != subCount[input[i]])
            return false;
    }


    return true;
}

int main()
{
    cout << "Enter main string : ";
    string input;
    cin >> input;

    cout << "Enter string 1 : ";
    string str1;
    cin >> str1;

    cout << "Enter string 2 : ";
    string str2;
    cin >> str2;


    // Check if a string is a valid shuffle of two other strings
    bool check = checkShuffle(input, str1, str2);

    if(check){

        cout << "Valid Shuffle !!";
    }
    else{

        cout << "Not a Valid Shuffle !!";
    }


    cout << endl;
    return 0;
}