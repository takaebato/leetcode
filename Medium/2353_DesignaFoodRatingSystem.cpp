#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

// pairのsetで保持するのが工夫点
class FoodRatings {
   public:
    unordered_map<string, pair<int, string>> food_rating_cuisine;
    unordered_map<string, set<pair<int, string>>> cuisine_rating_food;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        rep(i, foods.size()) {
            food_rating_cuisine[foods[i]] = {ratings[i], cuisines[i]};
            cuisine_rating_food[cuisines[i]].insert({-1 * ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        cuisine_rating_food[food_rating_cuisine[food].second].erase({-1 * food_rating_cuisine[food].first, food});
        cuisine_rating_food[food_rating_cuisine[food].second].insert({-1 * newRating, food});
        food_rating_cuisine[food].first = newRating;
    }

    string highestRated(string cuisine) { return cuisine_rating_food[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
