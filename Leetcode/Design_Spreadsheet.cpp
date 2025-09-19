#include <iostream>
#include <vector>
using namespace std;

class Spreadsheet {
  public:
      vector<int> grid;
  
      Spreadsheet(int rows) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          cout.tie(NULL);
  
          grid.resize(26 * (rows + 1), 0);
      }
  
      pair<int, int> getRowCol(string &cell) {
          int currIdx = 0;
          int colIdx = (cell[currIdx++] - 'A');
  
          int rowIdx = 0;
          while(currIdx < cell.size()) {
              rowIdx = (rowIdx * 10) + (cell[currIdx++]-'0');
          }
          return make_pair(rowIdx, colIdx);
      }
      
      void setCell(string cell, int value) {
          auto [rowIdx, colIdx] = getRowCol(cell);
          grid[26 * rowIdx + colIdx] = value;
      }
      
      void resetCell(string cell) {
          auto [rowIdx, colIdx] = getRowCol(cell);
          grid[26 * rowIdx + colIdx]  = 0;
      }
      
      int getValue(string formula) {
          int totalSum = 0;
          int currIdx = 1;
  
          string eqOne = "";
          string eqTwo = "";
  
          while(currIdx < formula.size() && formula[currIdx] != '+') {
              eqOne.push_back(formula[currIdx++]);
          }
  
          currIdx++;
          while(currIdx < formula.size()) {
              eqTwo.push_back(formula[currIdx++]);
          }
  
  
          // If the equation starts with character
          if(eqOne[0] >= 'A' && eqOne[0] <= 'Z') {
              auto [rowIdx, colIdx] = getRowCol(eqOne);
              totalSum += grid[26 * rowIdx + colIdx];
          }
          else 
              totalSum += stoi(eqOne);
  
  
          // If the equation starts with character
          if(eqTwo[0] >= 'A' && eqTwo[0] <= 'Z') {
              auto [rowIdx, colIdx] = getRowCol(eqTwo);
              totalSum += grid[26 * rowIdx + colIdx];
          }
          else 
              totalSum += stoi(eqTwo);
  
          return totalSum;
      }
  };
  
  /**
   * Your Spreadsheet object will be instantiated and called as such:
   * Spreadsheet* obj = new Spreadsheet(rows);
   * obj->setCell(cell,value);
   * obj->resetCell(cell);
   * int param_3 = obj->getValue(formula);
   */