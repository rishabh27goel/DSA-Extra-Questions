#include <iostream>
#include <vector>
using namespace std;

// Binary Search
// Time : O(log(n * m))   Space : O(1)
bool searchMatrix(vector< vector<int> >& mat, int target) {
    
    int n = mat.size();
    int m = mat[0].size();

    int start = 0;
    int end = (n * m)-1;

    while (start <= end) {
    
        int mid = start + (end - start) / 2;

        int i = mid / m;
        int j = mid % m;

        if (mat[i][j] == target) {
        
            return true;
        } 
        else if (mat[i][j] > target) {
        
            end = mid-1;
        } 
        else {
        
            start = mid+1;
        }
    }

    return false;
}

int main()
{
    cout << "Enter size : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > grid(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> grid[i][j];
        }
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    bool check = searchMatrix(grid, target);

    cout << (check ? "Present" : "Not Present");


    cout << endl;
    return 0;
}