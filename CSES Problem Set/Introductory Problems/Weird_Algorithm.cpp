#include <iostream>
using namespace std;

void getPattern(long number) {
    while(true) {
        cout << number << " ";
        if(number == 1)
            break;

        if(number & 1)
            number = (3 * number + 1);
        else
            number /= 2;
    }
}

int main()
{
    long number;
    cin >> number;

    getPattern(number);

    return 0;
}