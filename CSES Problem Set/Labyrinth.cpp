#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

char directionHelper(int n, int m, int pos1, int pos2) {
    int row1 = pos1 / m;
    int col1 = pos1 % m;

    int row2 = pos2 / m;
    int col2 = pos2 % m;

    if(row1 - row2 == 1)
        return 'D';
    
    else if(row1 - row2 == -1)
        return 'U';

    else if(col1 - col2 == 1)
        return 'R';

    else if(col1 - col2 == -1)
        return 'L';
}

void findPath(int n, int m, vector<string> &grid) {
    int src = -1;
    int dst = -1;

    vector< vector<int> > pathGrid(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'A') {
                src = i * m + j;
                grid[i][j] = '#';
            }
            else if(grid[i][j] == 'B')
                dst = i * m + j;

            pathGrid[i][j] = (i * m) + j;
        }
    }

    if(src == -1 || dst == -1) {
        cout << "NO" << endl;
        return;
    }

    queue<int> nodes;
    nodes.push(src);

    bool possible = false;
    while(!nodes.empty()) {
        int currNode = nodes.front();
        nodes.pop();

        int row = currNode / m;
        int col = currNode % m;

        if(currNode == dst) {
            possible = true;
            break;
        }

        int xPos[4] = {1, -1, 0, 0};
        int yPos[4] = {0, 0, 1, -1};
    
        for(int k=0; k<4; k++){
            int x = xPos[k] + row;
            int y = yPos[k] + col;

            if(x >= 0 && y >= 0 && x < n && y < m && (grid[x][y] == '.' || grid[x][y] == 'B')) {
                nodes.push(x * m + y);
                grid[x][y] = '#';
                pathGrid[x][y] = currNode; 
            }
        }
    }

    if(possible) {
        cout << "YES" << endl;
        
        string path = "";
        int i = dst / m;
        int j = dst % m;
        int node = dst;

        while(pathGrid[i][j] != node) {
            path.push_back(directionHelper(n, m, node, pathGrid[i][j]));

            node = pathGrid[i][j];
            i = node / m;
            j = node % m;
        }

        cout << path.size() << " " << endl;
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    findPath(n, m, grid);

    return 0;
}