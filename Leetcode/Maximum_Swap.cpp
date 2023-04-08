#include <iostream>
#include <string>
using namespace std;

// Method 1 : Checking for each digit 
// Time Complexity : O(n ^ 2)  Space Complexity : O(n)
// int maximumSwap(int n){

//     string strNum = to_string(n);

//     for(int i=0; i<strNum.size(); i++){

//         int dig = strNum[i]-'0';
//         int index = -1;

//         // If a greater element exists
//         for(int j=i+1; j<strNum.size(); j++){

//             if(strNum[i] != strNum[j]){

//                 if(dig <= (strNum[j]-'0')){

//                     dig =  strNum[j]-'0';
//                     index = j;
//                 }
//             }
//         }

//         if(index != -1){

//             swap(strNum[index], strNum[i]);
//             break;
//         }
//     }

//     return stoi(strNum);
// }

// Method 2 : Single Iteration [Linear Method] 
// Time Complexity : O(n)  Space Complexity : O(n)
int maximumSwap(int n){

    string strNum = to_string(n);

    int leftInd = -1;
    int rightInd = -1;

    int maxInd = -1;
    int maxNum = -1;

    for(int i=strNum.size()-1; i>=0; i--){

        // If current is the max number
        if(strNum[i]-'0' > maxNum){

            maxNum = strNum[i]-'0';
            maxInd = i;
        }
        else{

            if(maxNum > strNum[i]-'0'){

                leftInd = i;
                rightInd = maxInd;
            }
        }
    }
    
    if(leftInd == -1)
        return n;

    swap(strNum[leftInd], strNum[rightInd]);

    return stoi(strNum);
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    // Maximum Swap
    int result = maximumSwap(n);

    cout << "Maximum is : " << result;    


    cout << endl;
    return 0;
}