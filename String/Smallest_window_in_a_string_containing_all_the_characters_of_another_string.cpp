#include <iostream>
using namespace std;

// Method : Storing char count
// Time Complexity : O(n)  Space Complexity : O(26)
int smallestWindow(string &first, string &second){

    int n1 = first.size();
    int n2 = second.size();


    return -1;
}

int main()
{
    cout << "Enter first string : ";
    string first;
    cin >> first;

    cout << "Enter second string : ";
    string second;
    cin >> second;


    int size = smallestWindow(first, second);

    cout << "Smallest Window is : " << size;


    cout << endl;
    return 0;
}