/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fruit-into-baskets/
 * Runtime: 126ms (92.45%)
 */

class Solution {
#define MAXN 100001
public:
  int totalFruit(vector<int>& fruits) {
    vector<int> count(MAXN, 0);
    int types = 0;
    int l = 0;
    int answer = 0;
    for (int r = 0; r < fruits.size(); ++r) {
      int& c = count[fruits[r]];
      if (c == 0 && types == 2) {
        while (--count[fruits[l++]] != 0) {}
      } else if (c == 0) {
        ++types;
      }
      ++c;
      answer = max(answer, r - l + 1);
    }
    return answer;
  }
};
