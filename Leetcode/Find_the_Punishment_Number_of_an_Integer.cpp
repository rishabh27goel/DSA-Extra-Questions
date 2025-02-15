#include <iostream>
using namespace std;

// class Solution {
// public:
//     int punishment[1001];
//     bool validSquare = false;

//     Solution() {
//         int totalSum = 0;
//         for(int number = 1; number <= 1000; number++) {
//             string squareNumber = to_string(number * number);
            
//             int size = squareNumber.size();
//             validSquare = false;

//             checkSquarePartition(size, number, squareNumber, 0, 0);

//             if(validSquare)   totalSum += (number * number);
//             punishment[number] = totalSum;
//         } 
//     }
    
//     void checkSquarePartition(int size, int targetSum, string &squareNumber, int currentIdx, int currentSum) {
//         if(validSquare)   return;
        
//         if(currentIdx >= size) {
//             if(currentSum == targetSum)   
//                 validSquare = true;

//             return;
//         }

//         int partitionSum = 0;
//         for(int squareIdx = currentIdx; squareIdx < size; squareIdx++) {
//             partitionSum = (partitionSum * 10 + (squareNumber[squareIdx] - '0'));

//             checkSquarePartition(size, targetSum, squareNumber, squareIdx + 1, currentSum + partitionSum);
//         }
//     }

//     int punishmentNumber(int n) {
//         ios_base::sync_with_stdio(false);
//         // cin.tie(NULL);
//         // cout.tie(NULL);

//         return punishment[n];
//     }
// };

class Solution {
public:
    bool validSquare = false;
    void checkSquarePartition(int size, int targetSum, string &squareNumber, int currentIdx, int currentSum) {
        if(validSquare)   return;
        
        if(currentIdx >= size) {
            if(currentSum == targetSum)   
                validSquare = true;

            return;
        }

        int partitionSum = 0;
        for(int squareIdx = currentIdx; squareIdx < size; squareIdx++) {
            partitionSum = (partitionSum * 10 + (squareNumber[squareIdx] - '0'));

            checkSquarePartition(size, targetSum, squareNumber, squareIdx + 1, currentSum + partitionSum);
        }
    }

    int punishmentNumber(int n) {
        int totalSum = 0;
        for(int number = 1; number <= n; number++) {
            string squareNumber = to_string(number * number);
            
            int size = squareNumber.size();
            validSquare = false;

            checkSquarePartition(size, number, squareNumber, 0, 0);

            if(validSquare) 
                totalSum += (number * number);
        } 
        return totalSum;
    }
};