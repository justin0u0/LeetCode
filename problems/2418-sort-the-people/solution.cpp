/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-the-people/
 * Runtime: 22ms (88.58%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    const int n = names.size();
    vector<pair<int, string>> people(n);
    for (int i = 0; i < n; ++i) {
      people[i] = {heights[i], names[i]};
    }
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());
    for (int i = 0; i < n; ++i) {
      names[i] = people[i].second;
    }
    return names;
  }
};
