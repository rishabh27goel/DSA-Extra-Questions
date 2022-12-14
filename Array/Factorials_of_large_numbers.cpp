#include <iostream>
#include <vector>
using namespace std;

vector<int> findFactorial(int n){

    vector<int> result;
    result.push_back(1);

    if(n == 1)
        return result;


    for(int i=2; i<=n; i++){

        int carry = 0;

        for(int j=0; j<result.size(); j++){

            int mul = (result[j] * i) + carry;

            result[j] = mul % 10;
            carry = mul / 10;
        }

        if(carry != 0){

            while(carry != 0){

                result.push_back(carry % 10);
                carry = carry / 10;
            }
        }
    }

    // Reverse the array
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Factorials of large numbers
    vector<int> factorial = findFactorial(n);

    cout << "Factorial is : ";

    for(int i=0; i<factorial.size(); i++){

        cout << factorial[i];
    }


    cout << endl;
    return 0;
}