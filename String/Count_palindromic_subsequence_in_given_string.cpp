#include <iostream>
using namespace std;

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    int total = countPalindromicSubsequences(input);

    cout << "Total Count : " << total;
    

    cout << endl; 
    return 0;
}