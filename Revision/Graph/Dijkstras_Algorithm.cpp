#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter number of edges : ";
    int m;
    cin >> m;


    vector< pair<int, int> > edges;

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;

        edges.push_back(make_pair(u, v));
    }

    



    cout << endl;
    return 0;
}