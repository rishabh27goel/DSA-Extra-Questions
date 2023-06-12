#include <iostream>
using namespace std;

// Greedy Approach
// Time : O(n * log(n))  Space : O(1)
vector< vector<int> > mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    vector< vector<int> > result;

    sort(intervals.begin(), intervals.end(), 
        [&](const vector<int> &v1, const vector<int> &v2) {

       if(v1[0] == v2[0])
            return v1[1] < v2[1];

       return v1[0] < v2[0];
    });

    int start = intervals[0][0];
    int maxEnd = intervals[0][1];

    for (int i = 1; i < n; i++) {

      // We can merge
      if (maxEnd >= intervals[i][0]){
      
          maxEnd = max(intervals[i][1], maxEnd);
      }
      else{

          result.push_back({start, maxEnd});
          
          start = intervals[i][0];
          maxEnd = intervals[i][1];
      }
    }

    result.push_back({start, maxEnd});

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector< vector<int> > pairs;

    for(int i=0; i<n; i++){

        int a, b;
        cin >> a >> b;

        pairs.push_back({a, b});
    }


    vector< vector<int> > merged =  mergeIntervals(pairs);


    cout << "Merged Interval : \n";

    for(int i=0; i<merged.size(); i++){

        for(int j=0; j<merged[i].size(); j++){

            cout << merged[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}