#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      // int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
      //     unordered_set<int> sadUsers;
      //     for(auto &friends : friendships) {
      //         int u = friends[0] - 1;
      //         int v = friends[1] - 1;
              
      //         unordered_set<int> knowLang;
      //         bool canTalk = false;
  
      //         for(int &lang : languages[u]) {
      //             knowLang.insert(lang);
      //         }
      //         for(int &lang : languages[v]) {
      //             if(knowLang.find(lang) != knowLang.end()) {
      //                 canTalk = true;
      //                 break;
      //             }
      //         }
      //         if(!canTalk) {
      //             sadUsers.insert(u);
      //             sadUsers.insert(v);
      //         }   
      //     }
  
      //     vector<int> languageCount(n + 1, 0);
      //     int maxUserCount = 0;
  
      //     for(int user : sadUsers) {
      //         for(int &lang : languages[user]) {
      //             maxUserCount = max(maxUserCount, ++languageCount[lang]);
      //         }
      //     }
      //     return sadUsers.size() - maxUserCount;
      // }
  
      int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
          ios_base::sync_with_stdio(false);
          // cin.tie(NULL);
          // cout.tie(NULL);
  
          int totalUsers = languages.size();
          
          vector<int> sadUsers(totalUsers, false);
          for(auto &friends : friendships) {
              int u = friends[0] - 1;
              int v = friends[1] - 1;
              
              vector<bool> knowLang(n + 1, false);
              bool canTalk = false;
  
              for(int &lang : languages[u]) {
                  knowLang[lang] = true;
              }
              for(int &lang : languages[v]) {
                  if(knowLang[lang]) {
                      canTalk = true;
                      break;
                  }
              }
              if(!canTalk) {
                  sadUsers[u] = true;
                  sadUsers[v] = true;
              }   
          }
  
          vector<int> languageCount(n + 1, 0);
          int totalSadUsers = 0;
          int maxUserCount = 0;
  
          for(int user = 0; user < totalUsers; user++) {
              if(!sadUsers[user])  continue;
              totalSadUsers++;
  
              for(int &lang : languages[user]) {
                  maxUserCount = max(maxUserCount, ++languageCount[lang]);
              }
          }
          return totalSadUsers - maxUserCount;
      }
  };