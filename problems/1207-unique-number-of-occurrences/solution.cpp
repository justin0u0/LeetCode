/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-number-of-occurrences/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int BASE = 1000;
  const int MAXN = BASE * 2 + 1;
  const int MAXO = 1001;
public:
  bool uniqueOccurrences(vector<int>& arr) {
    vector<int> count(MAXN, 0);
    for (const int& num : arr) {
      ++count[num + BASE];
    }

    vector<bool> occur(MAXO, false);
    for (const int& cnt : count) {
      if (cnt != 0 && occur[cnt]) {
        return false;
      }
      occur[cnt] = true;
    }

    return true;
  }
};
