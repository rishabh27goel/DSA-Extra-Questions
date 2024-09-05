#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string> &board, int row, int col) {
    // Check for same column
    for(int j = 0; j < 8; j++) {
        if(row != j && board[j][col] == 'Q')
            return false;
    }

    // Check for same row
    for(int j = 0; j < 8; j++) {
        if(col != j && board[row][j] == 'Q')
            return false;
    }

    // Check for diagonal 1
    int i = row - 1;
    int j = col + 1;

    while(i >= 0 && j < 8) {
        if(board[i][j] == 'Q')  return false;
        i--, j++;
    }

    // Check for diagonal 2
    i = row - 1;
    j = col - 1;

    while(i >= 0 && j >= 0) {
        if(board[i][j] == 'Q')  return false;
        i--, j--;
    }

    return true;
}

int findWays(vector<string> &board, int row) {
    // Base Case
    if(row == 8)
        return 1;

    int totalWays = 0;
    for(int j = 0; j < 8; j++) {
        if(board[row][j] == '.') {
            // If we are placing the queen in row 
            // Then we can not add more queen in current row
            if(isSafe(board, row, j)) {
                board[row][j] = 'Q';        
                totalWays += findWays(board, row + 1);
                board[row][j] = '.';
            }
        }
    }
    return totalWays;
}

int main()
{
    vector<string> board;
    for(int j = 0; j < 8; j++) {
        string input;
        getline(cin, input);
        board.push_back(input);
    }

    int ways = findWays(board, 0);
    cout << ways << endl;

    return 0;
}