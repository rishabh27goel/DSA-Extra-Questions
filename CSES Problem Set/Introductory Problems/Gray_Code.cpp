#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findGrayCode(int n) {
    vector<int> elements;
    elements.push_back(0);
    elements.push_back(1);

    if(n == 1)  return elements;

    for(int bit = 1; bit < n; bit++) {
        int mask = (1 << bit);
        for(int j = elements.size()-1; j >= 0; j--) {
            elements.push_back((elements[j] | mask));
        }
    }

    return elements;
}

string findBitString(int number, int n) {
    string str = "";
    for(int j = 0; j < n; j++) {
        str.push_back((number & (1 << j)) ? '1' : '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int n;
    cin >> n;

    vector<int> elements = findGrayCode(n);
    for(int i = 0; i < elements.size(); i++) {
        cout << findBitString(elements[i], n) << endl;
    }

    return 0;
}