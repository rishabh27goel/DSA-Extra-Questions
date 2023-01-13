#include <iostream>
using namespace std;

string largestSubstring(string &number){

    int n = number.size();

    for(int i=n-1; i>=0; i--){

        int val = number[i]-'0';
        
        if(val & 1){

            return number.substr(0, i+1);
        }
    }

    return "";
}

int main()
{
    cout << "Enter number : ";
    string number;
    cin >> number;

    // Sort by frequency
    string result = largestSubstring(number);

    cout << "Result is : " << result;



    cout << endl;
    return 0;
}