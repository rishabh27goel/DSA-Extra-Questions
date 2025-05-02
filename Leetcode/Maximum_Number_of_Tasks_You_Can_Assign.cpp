#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
  public:
      bool canAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength, int currTask) {        
          multiset<int> workersSet(workers.end() - currTask, workers.end());
          for(int currIdx = currTask - 1; currIdx >= 0; currIdx--) {
              auto currWorker = --workersSet.end();
  
              if(*currWorker < tasks[currIdx]) {
                  if(pills <= 0)  
                      return false;
  
                  auto weakestWorker = workersSet.lower_bound(tasks[currIdx] - strength);
                  if(weakestWorker == workersSet.end()) 
                      return false;
  
                  pills--;
                  workersSet.erase(weakestWorker);
              }
              else {
                  workersSet.erase(currWorker);
              }
          }
          return true;
      }   
  
      int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {  
          int taskSize = tasks.size();
          int workerSize = workers.size();
  
          sort(tasks.begin(), tasks.end());
          sort(workers.begin(), workers.end());
  
          int maxTask = 0;
          int lowTask = 0;
          int highTask = min(taskSize, workerSize);
  
          while(lowTask <= highTask) {
              int midTask = lowTask + (highTask - lowTask) / 2;
              if(canAssign(tasks, workers, pills, strength, midTask)) {
                  maxTask = midTask;
                  lowTask = midTask + 1;
              }
              else {
                  highTask = midTask - 1;
              }
          }
          return maxTask;
      }
  };