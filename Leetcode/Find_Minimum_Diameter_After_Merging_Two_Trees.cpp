#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findDiameter(vector<vector<int>> &adjList, int start, int parent, int &diameter)
  {
    int firstMax = 0;
    int secondMax = 0;

    for (auto &child : adjList[start])
    {
      if (child == parent)
        continue;

      int childDepth = findDiameter(adjList, child, start, diameter);

      if (firstMax < childDepth)
      {
        secondMax = firstMax;
        firstMax = childDepth;
      }
      else if (secondMax < childDepth)
      {
        secondMax = childDepth;
      }
    }

    diameter = max(diameter, firstMax + secondMax);
    return firstMax + 1;
  }

  int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> adjListA(n);
    for (int j = 0; j < n - 1; j++)
    {
      int u = edges1[j][0];
      int v = edges1[j][1];

      adjListA[u].push_back(v);
      adjListA[v].push_back(u);
    }

    vector<vector<int>> adjListB(m);
    for (int j = 0; j < m - 1; j++)
    {
      int u = edges2[j][0];
      int v = edges2[j][1];

      adjListB[u].push_back(v);
      adjListB[v].push_back(u);
    }

    int diameterA = 0;
    findDiameter(adjListA, 0, -1, diameterA);

    int diameterB = 0;
    findDiameter(adjListB, 0, -1, diameterB);

    int minDiameter = ((diameterA + 1) / 2) + ((diameterB + 1) / 2) + 1;
    minDiameter = max(minDiameter, diameterA);
    minDiameter = max(minDiameter, diameterB);

    return minDiameter;
  }
};