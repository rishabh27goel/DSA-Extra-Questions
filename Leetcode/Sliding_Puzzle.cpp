#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // string getBoardView(vector<vector<int>> &board) {
    //     string number = "";
    //     for(int i = 0; i < 2; i++) {
    //         for(int j = 0; j < 3; j++) {
    //             number.push_back((char) (board[i][j] + '0'));
    //         }
    //     }
    //     return number;
    // }

    // pair<int, int> getEmptyCell(string &board) {
    //     for(int k = 0; k < board.size(); k++) {
    //         if(board[k] == '0')
    //             return {k / 3, k % 3};
    //     }
    //     return {-1, -1};
    // }

    // void getCurrentBoard(vector<vector<int>> &board, string &current) {
    //     board.resize(2, vector<int> (3));
    //     int idx = 0;
    //     for(int i = 0; i < 2; i++) {
    //         for(int j = 0; j < 3; j++) {
    //             board[i][j] = (current[idx++] - '0');
    //         }
    //     }
    // }

    // int slidingPuzzle(vector<vector<int>>& board) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = 2;
    //     int m = 3;

    //     string startPos = getBoardView(board);

    //     queue<string> posQ;
    //     posQ.push(startPos);

    //     unordered_set<string> visited;
    //     visited.insert(startPos);

    //     int xPos[4] = {1, -1, 0, 0};
    //     int yPos[4] = {0, 0, 1, -1};

    //     int moves = 0;
    //     while(!posQ.empty()) {
    //         int size = posQ.size();

    //         while(size--) {
    //             string currPos = posQ.front();
    //             posQ.pop();

    //             if(currPos == "123450")
    //                 return moves;

    //             auto cell = getEmptyCell(currPos);
    //             for(int k = 0; k < 4; k++) {
    //                 int x = xPos[k] + cell.first;
    //                 int y = yPos[k] + cell.second;

    //                 if(x >= 0 && y >= 0 && x < n && y < m) {
    //                     vector<vector<int>> currBoard;
    //                     getCurrentBoard(currBoard, currPos);

    //                     swap(currBoard[cell.first][cell.second], currBoard[x][y]);
    //                     string nextPos = getBoardView(currBoard);

    //                     if(visited.find(nextPos) == visited.end()) {
    //                         posQ.push(nextPos);
    //                         visited.insert(nextPos);
    //                     }

    //                     swap(currBoard[cell.first][cell.second], currBoard[x][y]);
    //                 }
    //             }

    //         }
    //         moves++;
    //     }

    //     return -1;
    // }

    string getBoardView(vector<vector<int>> &board) {
        string number = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                number.push_back((char) (board[i][j] + '0'));
            }
        }
        return number;
    }

    int getEmptyCell(string &board) {
        for(int k = 0; k < board.size(); k++) {
            if(board[k] == '0')
                return k;
        }
        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = 2;
        int m = 3;

        string startPos = getBoardView(board);
        string finalPos = "123450";

        queue<string> posQ;
        posQ.push(startPos);

        unordered_set<string> visited;
        visited.insert(startPos);

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};

        int moves = 0;
        while(!posQ.empty()) {
            int size = posQ.size();

            while(size--) {
                string currPos = posQ.front();
                posQ.pop();

                if(currPos == finalPos)
                    return moves;

                int cell = getEmptyCell(currPos);
                int row = cell / m;
                int col = cell % m;

                for(int k = 0; k < 4; k++) {
                    int x = row + xPos[k];
                    int y = col + yPos[k];

                    if(x >= 0 && y >= 0 && x < n && y < m) {
                        int next = x * m + y;
                        swap(currPos[next], currPos[cell]);

                        if(visited.find(currPos) == visited.end()) {
                            posQ.push(currPos);
                            visited.insert(currPos);
                        }
                        swap(currPos[next], currPos[cell]);
                    }
                }

            }
            moves++;
        }

        return -1;
    }
};