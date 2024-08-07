#include <iostream>
using namespace std;

class Solution {
public:
    string numberHelper(int number){
        if(number == 0)         return "Zero ";
        else if(number == 1)    return "One ";
        else if(number == 2)    return "Two ";
        else if(number == 3)    return "Three ";
        else if(number == 4)    return "Four ";
        else if(number == 5)    return "Five ";
        else if(number == 6)    return "Six ";
        else if(number == 7)    return "Seven ";
        else if(number == 8)    return "Eight ";
        else if(number == 9)    return "Nine ";
        else if(number == 10)    return "Ten ";
        else if(number == 11)    return "Eleven ";
        else if(number == 12)    return "Twelve ";
        else if(number == 13)    return "Thirteen ";
        else if(number == 14)    return "Fourteen ";
        else if(number == 15)    return "Fifteen ";
        else if(number == 16)    return "Sixteen ";
        else if(number == 17)    return "Seventeen ";
        else if(number == 18)    return "Eighteen ";
        else if(number == 19)    return "Nineteen ";
        
        else if(number == 20)    return "Twenty ";
        else if(number == 30)    return "Thirty ";
        else if(number == 40)    return "Forty ";
        else if(number == 50)    return "Fifty ";
        else if(number == 60)    return "Sixty ";
        else if(number == 70)    return "Seventy ";
        else if(number == 80)    return "Eighty ";
        else if(number == 90)    return "Ninety ";

        else if(number == 100)    return "Hundred ";
        else if(number == 1000)    return "Thousand ";
        else if(number == 1000000)    return "Million ";
        else if(number == 1000000000)    return "Billion ";

        return " ";
    }

    string numberToWordsHelper(int num) {
        if(num == 0)  return numberHelper(0);

        if(num >= 1000000000){
            int mul = num / 1000000000;
            int rem = num % 1000000000;

            string str = numberToWordsHelper(mul);
            str += numberHelper(1000000000);
            if(rem != 0)   str += numberToWordsHelper(rem);

            return str;
        }
        else if(num >= 1000000){
            int mul = num / 1000000;
            int rem = num % 1000000;

            string str = numberToWordsHelper(mul);
            str += numberHelper(1000000);
            if(rem != 0)   str += numberToWordsHelper(rem);

            return str;
        }
        else if(num >= 1000){
            int mul = num / 1000;
            int rem = num % 1000;

            string str = numberToWordsHelper(mul);
            str += numberHelper(1000);
            if(rem != 0)   str += numberToWordsHelper(rem);

            return str;
        }
        else if(num >= 100){
            int mul = num / 100;
            int rem = num % 100;

            string str = numberToWordsHelper(mul);
            str += numberHelper(100);
            if(rem != 0)   str += numberToWordsHelper(rem);

            return str;
        }
        else if(num <= 19 && num >= 11){
            return numberHelper(num);
        }
        else {
            int lastDig = num % 10;
            int secLastDig =  num - lastDig;

            string str = "";
            if(secLastDig != 0)     str += numberHelper(secLastDig);
            if(lastDig != 0)        str += numberHelper(lastDig);
            return str;
        
        }
    }

    string numberToWords(int num) {
        string result = numberToWordsHelper(num);
        result.pop_back();
        return result;
    }
};