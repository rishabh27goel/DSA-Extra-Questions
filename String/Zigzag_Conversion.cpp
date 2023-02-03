#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n)  Space Complexity : O(n) 
// string findZigZag(string &input, int k){
    
//     if(k == 1)
//         return input;

//     vector <string> zigzag(k, "");

//     bool direction = false;
//     int j = 0;
//     int inc = 0;

//     while(j < input.size()){

//         if(inc == 0){

//             direction = false;
//         }
//         else if(inc == k-1){

//             direction = true;
//         }

//         zigzag[inc] += input[j];

//         inc += direction ? -1 : 1;
//         j++;
//     }

//     string output = "";

//     for(int i=0; i<k; i++){

//         output += zigzag[i];
//     }

//     return output;
// }

// Method 2 : Space Optimised
// Time Complexity : O(n)  Space Complexity : O(1) 
string findZigZag(string &input, int k){
    
    if(k == 1)
        return input;

    string result = "";

    for(int i=0; i<k; i++){

        if(i == 0 || i == k-1){

            int j = i;

            while(j < input.size()){

                result += input[j];
                j += (2 * (k-1));
            }
        }
        else{

            int j = i;

            while(j < input.size()){

                int mid = j + (2 * (k - i - 1));

                result += input[j];

                if(mid < input.size())
                    result += input[mid];

                j += (2 * (k-1));
            }
        }
    }

    return result;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    cout << "Enter k : ";
    int k;
    cin >> k;


    string result = findZigZag(input, k);

    cout << "ZigZag String : " << result;




    cout << endl;
    return 0;
}