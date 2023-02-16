#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > result;

bool isSafe(int n, int m, int x, int y){

    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;

    return true;
}

void findMatch(int n, int m, vector< vector<char> > &grid, string &word, int i, int j, int moveX, int moveY, int &ind){

    if(ind+1 == word.size())
        return;
        
    if(isSafe(n, m, i+moveX, j+moveY) && ind+1 < word.size() && word[ind+1] == grid[i+moveX][j+moveY]){

        ind++;
        findMatch(n, m, grid, word, i+moveX, j+moveY, moveX, moveY, ind);
    }
}

vector< pair<int, int> > findWordInGrid(int n, int m, vector< vector<char> > &grid, string &word){

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            if(grid[i][j] == word[0]){

                int xPos[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int yPos[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

                for(int k=0; k<8; k++){

                    int ind = 0;
                    findMatch(n, m, grid, word, i, j, xPos[k], yPos[k], ind);

                    if(ind == word.size()-1){

                        result.push_back(make_pair(i, j));
                    }
                }
                
            }
        }
    }

    return result;
}

int main()
{
    cout << "Enter grid : ";
    int n, m;
    cin >> n >> m;

    vector< vector<char> > grid(n, vector<char> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }
 
    cout << "Enter word : ";
    string word;
    cin >> word;


    cout << "Result is : \n";
    vector< pair<int, int> > result = findWordInGrid(n, m, grid, word);

    for(int i=0; i<result.size(); i++){

        cout << result[i].first << " " << result[i].second << endl;
    }


    cout << endl;
    return 0;
}