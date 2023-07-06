#include <iostream>
#include <queue>
using namespace std;

class Info {

    public:
        int data;
        int row;
        int col;

    Info(int data, int row, int col){

        this->data = data;
        this->col = col;
        this->row = row;
    }
};

class Compare {

    public:
      bool operator()(Info *f1, Info *f2) {

          return f1->data > f2->data;
      }
};

vector<int>
mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {

    int n = kArrays.size();

    vector<int> result;
    priority_queue<Info *, vector<Info *>, Compare> pq;

    for (int i = 0; i < n; i++) {

        pq.push(new Info(kArrays[i][0], i, 0));
    }

    while(!pq.empty()){

        Info* info = pq.top();
        pq.pop();

        result.push_back(info->data);

        if (info->col + 1 < kArrays[info->row].size()) {
        
            pq.push(new Info(kArrays[info->row][info->col + 1], info->row, info->col+1));
        }
    }

    return result;
}