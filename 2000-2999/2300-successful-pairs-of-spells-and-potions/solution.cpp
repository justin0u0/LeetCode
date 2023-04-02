/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
 * Runtime: 222ms (96.25%)
 */

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());

    vector<int> answer;
    answer.reserve(spells.size());
    for (const int& s : spells) {
      long long low = (success - 1) / s + 1;
      answer.emplace_back(potions.end() - lower_bound(potions.begin(), potions.end(), low));
    }
    return answer;
  }
};
