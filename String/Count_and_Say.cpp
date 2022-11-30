#include <iostream>
using namespace std;

// Using Recursion 
// Time Complexity : O(length of output)  Space Complexity : O(length of output)
string countAndSay(int n){

    // Base Case
    if(n == 1)
        return "1";


    string str = countAndSay(n-1);

    string output = "";
    int i = 0;

    while(i < str.size()){

        int count = 0;
        char val = str[i];

        while(i < str.size() && str[i] == val){

            count++;
            i++;
        }

        output += (char) (count + '0');
        output += val;
    }

    return output;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Count and Say
    string say = countAndSay(n);

    cout << "Output is : " << say;


    cout << endl;
    return 0;
}