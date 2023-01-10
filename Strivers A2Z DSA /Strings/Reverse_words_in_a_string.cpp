#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

// Method 1 : Using String Stream
// Time Complexity : O(n)  Space Complexity : O(n)
// string reverseWords(string &input){

//     vector<string> words;

//     stringstream ss(input);
//     string word;

//     while(ss >> word){

//         words.push_back(word);
//     }


//     string str = words[0];
        
//     if(words.size() == 1)
//         return str;
        

//     for(int i=1; i<words.size()-1; i++){

//         str = words[i] + ' ' + str;
//     }
    
//     str = words[words.size()-1] + ' ' + str;

//     return str;
// }

// Method 2 : Using Stack
// Time Complexity : O(n)  Space Complexity : O(n)
// string reverseWords(string &input){

//     int n = input.size();

//     stack <string> st;
//     string word = "";

//     int j = 0;

//     while(j < n){

//         if(input[j] == ' '){

//             st.push(word);
//             word = "";
//         }
//         else{

//             word += input[j];
//         }

//         j++;
//     }

//     st.push(word);


//     string str = "";

//     while(st.size() != 1){

//         str += st.top();
//         str += ' ';

//         st.pop();
//     }

//     str += st.top();

//     return str;
// }

// Method 3 : Without Extra Space
// Time Complexity : O(n)  Space Complexity : O(1)
// string reverseWords(string &input){

//     int n = input.size();

//     string str = "";
//     string word = "";

//     int j = 0;

//     while(j < n){

//         if(input[j] == ' '){

//             str = word + str;
//             str = " " + str;

//             word = "";
//         }
//         else{

//             word += input[j];
//         }

//         j++;
//     }

//     str = word + str;

//     return str;
// }

// Method 4 : Without Extra Space [Second Way]
// Time Complexity : O(n)  Space Complexity : O(1)
string reverseWords(string &input){

    int n = input.size();

    string str = "";
    string word = "";

    int end = n-1;
    int j = n-1;


    while(j >= 0){

        if(input[j] == ' '){

            for(int i=j+1; i<=end; i++){

                str += input[i];
            }

            str += ' ';
            j--;
            end = j;
        }
        else{

            j--;
        }        
    }

    for(int i=0; i<=end; i++){

        str += input[i];
    }

    return str;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    getline(cin, input);

    // Reverse Words in a String
    string str = reverseWords(input);

    cout << "Updated String : " << str;


    cout << endl;
    return 0;
}