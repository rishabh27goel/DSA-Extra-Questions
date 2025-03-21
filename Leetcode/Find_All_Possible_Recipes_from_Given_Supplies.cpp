#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
  public:
      // Here, I have not taken the current suppiles into account
  
      // vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      //     int totalRecipes = recipes.size();
  
      //     unordered_map<string, vector<string>> adjList;
      //     unordered_map<string, int> ingredientsDegree;
      //     unordered_set<string> reciptToCreateMap;
  
      //     for(int reciptIdx = 0; reciptIdx < totalRecipes; reciptIdx++) {
      //         auto &list = ingredients[reciptIdx];
      //         auto &currRecipt = recipes[reciptIdx];
  
      //         for(auto &ingredient : list) {
      //             ingredientsDegree[ingredient] += 0;
      //             adjList[ingredient].push_back(currRecipt);
      //         }
  
      //         ingredientsDegree[currRecipt] += list.size();            
      //         reciptToCreateMap.insert(currRecipt);
      //     }
  
      //     queue<string> currentIngredient;
      //     for(auto ingredient : ingredientsDegree) {
      //         if(ingredient.second == 0)
      //             currentIngredient.push(ingredient.first);
      //     }
      
      //     vector<string> recipesResultList;
      //     while(!currentIngredient.empty()) {
      //         auto currNode = currentIngredient.front();
      //         currentIngredient.pop();
  
      //         if(reciptToCreateMap.find(currNode) != reciptToCreateMap.end())
      //             recipesResultList.push_back(currNode);
  
      //         for(auto &childNode : adjList[currNode]) {
      //             if(--ingredientsDegree[childNode] == 0) {
      //                 currentIngredient.push(childNode);
      //             }
      //         }
      //     }
      //     return recipesResultList;
      // }
  
      vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
          int totalRecipes = recipes.size();
  
          unordered_map<string, vector<string>> adjList;
          unordered_map<string, int> ingredientsDegree;
          unordered_set<string> reciptToCreateMap;
  
          for(int reciptIdx = 0; reciptIdx < totalRecipes; reciptIdx++) {
              auto &list = ingredients[reciptIdx];
              auto &currRecipt = recipes[reciptIdx];
  
              for(auto &ingredient : list) {
                  ingredientsDegree[ingredient] += 0;
                  adjList[ingredient].push_back(currRecipt);
              }
  
              ingredientsDegree[currRecipt] += list.size();            
              reciptToCreateMap.insert(currRecipt);
          }
  
          // This step is important as we want to start from the supplies
          queue<string> currentIngredient;
          for(auto ingredient : supplies) {
              currentIngredient.push(ingredient);
          }
      
          vector<string> recipesResultList;
          while(!currentIngredient.empty()) {
              auto currNode = currentIngredient.front();
              currentIngredient.pop();
  
              if(reciptToCreateMap.find(currNode) != reciptToCreateMap.end())
                  recipesResultList.push_back(currNode);
  
              for(auto &childNode : adjList[currNode]) {
                  if(--ingredientsDegree[childNode] == 0) {
                      currentIngredient.push(childNode);
                  }
              }
          }
          return recipesResultList;
      }
  };