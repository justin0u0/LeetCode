/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
 * Runtime: 19ms (99.60%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, bool> got;
    for (const auto& s : supplies) {
      got.emplace(s, true);
    }

    unordered_map<string, int> rid;
    const int n = recipes.size();
    for (int i = 0; i < n; ++i) {
      rid.emplace(recipes[i], i);
    }

    function<bool(const string&)> test = [&](const string& s) {
      auto it = got.find(s);
      if (it != got.end()) {
        return it->second;
      }

      auto rit = rid.find(s);
      if (rit == rid.end()) {
        return false;
      }

      got.emplace(s, false);

      for (const auto& ing : ingredients[rit->second]) {
        if (!test(ing)) {
          return false;
        }
      }

      got.at(s) = true;
      return true;
    };

    vector<string> res;
    for (const auto& s : recipes) {
      if (test(s)) {
        res.emplace_back(s);
      }
    }
    return res;
  }
};
