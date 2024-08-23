#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();

        vector<pair<long, long>> values;
        long denominatorMul = 1;

        int j = 0;
        while(j < n) {
            int sign = 0;
            if(j < n && (expression[j] == '-' || expression[j] == '+')) {
                sign = (expression[j] == '-' ? 1 : 0);
                j++;
            }
                
            long numerator = 0;
            long denominator = 0;

            while(j < n && expression[j] >= '0' && expression[j] <= '9') {
                int dig = (expression[j] - '0');
                numerator = (numerator * 10) + dig;
                j++;
            }

            if(j < n && expression[j] == '/') {
                j++;
            }

            while(j < n && expression[j] >= '0' && expression[j] <= '9') {
                int dig = (expression[j] - '0');
                denominator = (denominator * 10) + dig;
                j++;
            }
            if(sign)  numerator = -numerator;

            denominatorMul *= denominator;
            values.push_back({ numerator, denominator });
        }

        long numeratorValue = 0;
        for(int j = 0; j < values.size(); j++){
            long currMul = (values[j].first * (denominatorMul / values[j].second));
            numeratorValue += currMul;
        }

        int sign = 0;
        if(numeratorValue < 0) {
            sign = 1;
            numeratorValue = -numeratorValue;
        }
       
        long gcd = findGCD(numeratorValue, denominatorMul);
        numeratorValue /= gcd;
        denominatorMul /= gcd;

        string result = (sign == 1) ? "-" : "";
        result += to_string(numeratorValue);
        result += "/";
        result += to_string(denominatorMul);

        return result;
    }

    long findGCD(long x, long y) {
        if(x == 0)
            return y;

        return findGCD(y % x, x);
    }
};