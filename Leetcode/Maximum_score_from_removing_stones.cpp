#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;

    int b;
    cin >> b;

    int c;
    cin >> c;

    // Maximum Score
    int maxNum = max(a, max(b, c));
    int minNum = min(a, min(b, c));
    int midOne = (a + b + c) - maxNum - minNum;

    if(minNum + midOne <= maxNum)
        cout << "Maximum Score is : " << minNum + midOne;
    else
        cout << "Maximum Score is : " << maxNum + ((minNum + midOne - maxNum) / 2);


    cout << endl;
    return 0;
}