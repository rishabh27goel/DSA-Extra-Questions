#include <iostream>
#include <stack>
using namespace std;

// Method 1 : Using Stack
// Time Complexity : O(n)   Space Complexity : O(n)
// string removeOutermostParenthesis(string &input){

//     int n = input.size();

//     string result = "";
//     stack<char> st;

//     for(int i=0; i<input.size(); i++){

//         if(input[i] == '('){

//             // Atleast 1 '(' in the stack
//             if(st.size() > 0){

//                 result += '(';
//             }

//             st.push('(');
//         }
//         else{

//             // Atleast 2 '(' in the stack
//             if(st.size() > 1){

//                 result += ')';
//             }

//             st.pop();
//         }
//     }

//     return result;
// }

// Method 2 : Without Extra Space
// Time Complexity : O(n)   Space Complexity : O(1)
string removeOutermostParenthesis(string &input){

    int n = input.size();

    string result = "";
    int opening = 0;

    for(int i=0; i<input.size(); i++){

        if(input[i] == '('){

            // Atleast 1 '(' in the stack
            if(opening > 0){

                result += '(';
            }

            opening++;
        }
        else{

            // Atleast 2 '(' in the stack
            if(opening > 1){

                result += ')';
            }

            opening--;
        }
    }

    return result;
}

int main()
{
    cout << "Enter input string : ";
    string input;
    cin >> input;

    string str = removeOutermostParenthesis(input);

    cout << "Optimised String : " << str;


    cout << endl;
    return 0;
}