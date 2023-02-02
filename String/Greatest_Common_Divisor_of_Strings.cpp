#include <iostream>
#include <algorithm>
using namespace std;

// Method : Brute Force
// Time Complexity : O(n)  Space Complexity : O(1)
int findGCD(int a, int b){

    if(b == 0)
        return a; 

    return findGCD(b, a % b);
}

string findGCDString(string &s1, string &s2){

    int n1 = s1.size();
    int n2 = s2.size();

    if(s1 + s2 == s2 + s1)
        return s1.substr(0, findGCD(n1, n2));

    return "";
}

int main()
{
    cout << "Enter first string : ";
    string first;
    cin >> first;

    cout << "Enter second string : ";
    string second;
    cin >> second;

    string gcd = findGCDString(first, second);

    cout << "GCD of String : " << gcd;


    cout << endl;
    return 0;
}