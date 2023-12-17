/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-a-food-rating-system/
 * Runtime: 375ms (88.04%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class FoodRatings {
private:
  class Food {
  public:
    const string name;
    int rating;

    Food(const string name, int rating) : name(name), rating(rating) {}

    bool operator<(const Food& rhs) const {
      return rating < rhs.rating || (rating == rhs.rating && name > rhs.name);
    }
  };

  unordered_map<string, set<Food>> cr;  // cuisine ratings
  unordered_map<string, int> fr;        // food rating
  unordered_map<string, string> fc;     // food to cuisine
public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    const int n = foods.size();
    for (int i = 0; i < n; ++i) {
      cr[cuisines[i]].emplace(foods[i], ratings[i]);
      fr[foods[i]] = ratings[i];
      fc[foods[i]] = cuisines[i];
    }
  }
  
  void changeRating(const string& food, int newRating) {
    auto& r = cr[fc[food]];
    r.erase(Food(food, fr[food]));
    r.emplace(Food(food, newRating));
    fr[food] = newRating;
  }
  
  string highestRated(const string& cuisine) {
    return cr[cuisine].rbegin()->name;
  }
};
