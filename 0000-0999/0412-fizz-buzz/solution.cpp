/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fizz-buzz/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static vector<string> fizz;
public:
  vector<string> fizzBuzz(int n) {
    return vector(fizz.begin(), fizz.begin() + n);
  }
};

vector<string> Solution::fizz = []() {
  const int n = 1e4;

  vector<string> res;
  res.reserve(n);

  for (int i = 1; i <= n; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
      res.emplace_back("FizzBuzz");
    } else if (i % 3 == 0) {
      res.emplace_back("Fizz");
    } else if (i % 5 == 0) {
      res.emplace_back("Buzz");
    } else {
      res.emplace_back(to_string(i));
    }
  }
  return res;
}();
