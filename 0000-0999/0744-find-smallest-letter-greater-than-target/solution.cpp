/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 * Runtime: 11ms (94.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    auto it = upper_bound(letters.begin(), letters.end(), target);
    if (it == letters.end()) {
      return letters[0];
    }

    return *it;
  }
};
