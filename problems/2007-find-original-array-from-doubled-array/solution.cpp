/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-original-array-from-doubled-array/
 * Runtime: 309ms (97.69%)
 * Time Complexity: O(N) where N is the MAX_VAL.
 */

class Solution {
private:
  const int MAX_VAL = 100000;
public:
  vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if (n & 1) {
      return vector<int>{};
    }

    vector<int> box(MAX_VAL + 1, 0);
    int minVal = MAX_VAL;
    int maxVal = 0;
    for (const int val : changed) {
      ++box[val];
      minVal = min(minVal, val);
      maxVal = max(maxVal, val);
    }

    vector<int> answer;
    answer.reserve(n >> 1);

    if (box[0] & 1) {
      return vector<int>{};
    }

    while (box[0] != 0) {
      answer.emplace_back(0);
      box[0] -= 2;
    }

    for (int i = minVal; i <= maxVal; ++i) {
      if (box[i] != 0) {
        int d = i << 1;
        if (d > maxVal || box[d] < box[i]) {
          return vector<int>{};
        }

        box[d] -= box[i];
        while (box[i] != 0) {
          answer.emplace_back(i);
          --box[i];
        }
      }
    }

    return answer;
  }
};
