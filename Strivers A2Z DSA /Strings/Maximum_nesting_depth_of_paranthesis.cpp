#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method 1 : Using Stack
// Time Complexity : O(n)  Space Complexity : O(n) 
// int maximumDepth(string &str){

//     int n = str.size();

//     int result = 0;
//     stack <char> st;

//     for(int i=0; i<n; i++){

//         if(str[i] == '('){

//             st.push('(');
//             result = max(result, (int) st.size());
//         }
//         else if(str[i] == ')'){

//             st.pop();
//         }
//     }

//     return result;
// }

// Method 1 : Without Extra Space
// Time Complexity : O(n)  Space Complexity : O(1) 
int maximumDepth(string &str){

    int n = str.size();

    int result = 0;
    int count = 0;

    for(int i=0; i<n; i++){

        if(str[i] == '('){

            count++;
            result = max(result, count);
        }
        else if(str[i] == ')'){

            count--;
        }
    }

    return result;
}

int main()
{
    cout << "Input String : ";
    string input;
    cin >> input;

    int depth = maximumDepth(input);

    cout << "Maximum Depth : " << depth;


    cout << endl;
    return 0;
}

