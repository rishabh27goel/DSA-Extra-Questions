#include <iostream>
using namespace std;

string convertToTitle(int columnNumber)
{
    string result = "";

    while (columnNumber){
        
        columnNumber--;

        result.push_back('A' + (columnNumber % 26));

        columnNumber /= 26;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    string str = convertToTitle(n);

    cout << "Result is : " << str;


    return 0;
}