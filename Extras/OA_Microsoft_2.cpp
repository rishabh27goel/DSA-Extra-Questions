#include <iostream>
#include <vector>
using namespace std;

int roadCount = 0;

void dfs(int n, vector< vector< pair<int, int> > > &adjList, int start, int parent) {
  for(int j = 0; j < adjList[start].size(); j++) {
    if(adjList[start][j].first == parent) continue;

    if(adjList[start][j].second == 1)
      roadCount++;

    dfs(n, adjList, adjList[start][j].first, start);
  }
}

int findMinimumRoads(vector<int> &arrU, vector<int> &arrV) {
  int n = arrU.size() + 1;

  vector< vector< pair<int, int> > > adjList(n);
  for(int j = 0; j < n-1; j++) {
    adjList[arrU[j]].push_back(make_pair(arrV[j], 1));
    adjList[arrV[j]].push_back(make_pair(arrU[j], -1));
  }

  dfs(n, adjList, 0, -1);

  return roadCount;
}

int main() {
  int n;
  cin >> n;

  vector<int> arrU(n);
  for(int j = 0; j < n; j++) {
    cin >> arrU[j];
  }

  vector<int> arrV(n);
  for(int j = 0; j < n; j++) {
    cin >> arrV[j];
  }

  int roads = findMinimumRoads(arrU, arrV);
  cout << roads << endl;

  return 0;
}