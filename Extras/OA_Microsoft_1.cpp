#include <iostream>
#include <vector>
using namespace std;

int findTotalCost(vector<int> &start, vector<int> &end, vector<int> &limits) {
  int k = limits.size();
  int n = start.size();

  int maxStation = -1;
  int totalFee = 0;

  for(int j = 0; j < n; j++) {
    maxStation = max(maxStation, start[j]);
    maxStation = max(maxStation, end[j]);

    int fee = (abs(start[j] - end[j]) * 2) + 1;
    totalFee += fee;
  }

  return min(totalFee, limits[maxStation]);
}

int main() 
{ 
  int n, k;
  cin >> n >> k;

  vector<int> start(n);
  for(int j = 0; j < n; j++) {
    cin >> start[j];
  }
 
  vector<int> end(n);
  for(int j = 0; j < n; j++) {
    cin >> end[j];
  }

  vector<int> limits(k);
  for(int j = 0; j < k; j++) {
    cin >> limits[j];
  }

  int cost = findTotalCost(start, end, limits);
  cout << cost << endl;


  return 0;  
}