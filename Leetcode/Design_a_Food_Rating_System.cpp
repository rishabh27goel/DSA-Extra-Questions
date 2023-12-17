#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class FoodRatings {
public:

    unordered_map<string, pair<int, string>> foodMap;
    unordered_map<string, set<pair<int, string>>> cuMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        for(int i=0; i<foods.size(); i++){

            foodMap[foods[i]] = {-ratings[i], cuisines[i]};
            cuMap[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        
        auto itr = cuMap[foodMap[food].second].find({foodMap[food].first, food});
        cuMap[foodMap[food].second].erase(itr);

        foodMap[food] = make_pair(-newRating, foodMap[food].second);
        cuMap[foodMap[food].second].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        
        auto highest = *(cuMap[cuisine].begin());

        return highest.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */