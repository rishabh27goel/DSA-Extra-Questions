#include <iostream>
#include <vector>
using namespace std;

class FoodRatings {
    private:
            struct compareFood {
                bool operator()(const pair<int, string> &p1, const pair<int, string> &p2) const {
                    if (p1.first == p2.first)
                        return p1.second < p2.second;
    
                    return p1.first > p2.first;
                }
            };
    
            unordered_map<string, set<pair<int, string>, compareFood>> cuisineToFoodListMap;
            unordered_map<string, pair<string, int>> foodInfoMap;
    
    public: 
        FoodRatings() {
            ios_base::sync_with_stdio(false);
            // cin.tie(NULL);
            cout.tie(NULL);
        }
    
        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            int size = foods.size();
            for(int currIdx = 0; currIdx < size; currIdx++) {
                string &cuisine = cuisines[currIdx];
                string &food = foods[currIdx];
                
                cuisineToFoodListMap[cuisine].insert(make_pair(ratings[currIdx], food));
                foodInfoMap[food] = make_pair(cuisine, ratings[currIdx]);
            }
        }
        
        void changeRating(string food, int newRating) {
            auto foodItr = foodInfoMap.find(food);
            auto info = foodItr->second;
            
            // Remove the cuisince
            string &cuisine = info.first;
            cuisineToFoodListMap[cuisine].erase(make_pair(info.second, food));
    
            // Add with new ratings
            cuisineToFoodListMap[cuisine].insert(make_pair(newRating, food));
            foodInfoMap[food] = make_pair(cuisine, newRating);
        }
        
        string highestRated(string cuisine) {
            return cuisineToFoodListMap[cuisine].begin()->second;
        }
    };
    
    /**
     * Your FoodRatings object will be instantiated and called as such:
     * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
     * obj->changeRating(food,newRating);
     * string param_2 = obj->highestRated(cuisine);
     */