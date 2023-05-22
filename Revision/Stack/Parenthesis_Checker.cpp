#include <iostream>
#include <stack>
using namespace std;

// Using Stack
// Time : O(n)  Space : O(n)
// bool parenthesisChecker(string &str){

//     int n = str.size();

//     unordered_map<char, char> mp;
//     mp['('] = ')';
//     mp['{'] = '}';
//     mp['['] = ']';

//     stack<char> st;

//     for(int i=0; i<n; i++){

//         if(str[i] == '(' || str[i] == '[' || str[i] == '{'){

//             st.push(str[i]);
//         }
//         else{

//             if(st.empty())
//                 return false;

//             if(mp[st.top()] == str[i]){

//                 st.pop();
//             }
//             else{

//                 return false;
//             }
//         }
//     } 

//     return st.empty();  
// }

// If we can modify input
// Time : O(n)  Space : O(1)
bool parenthesisChecker(string &str){

    int n = str.size();

    unordered_map<char, char> mp;
    mp['('] = ')';
    mp['{'] = '}';
    mp['['] = ']';

    int pointer = -1;

    for(int i=0; i<n; i++){

        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){

            str[++pointer] = str[i];
        }
        else{

            if(pointer == -1)
                return false;

            if(mp[str[pointer]] == str[i]){

                pointer--;
            }
            else{

                return false;
            }
        }
    }

    return pointer == -1;
}

int main()
{
    cout << "Enter string : ";
    string str;
    cin >> str;

    bool valid = parenthesisChecker(str);

    cout << (valid ? "Valid" : "Not Valid");


    cout << endl;
    return 0;
}