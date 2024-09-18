/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-number/
 * Runtime: 3ms (93.74%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> arr;
    arr.reserve(nums.size());
    for (int num : nums) {
      arr.emplace_back(to_string(num));
    }
    sort(arr.begin(), arr.end(), [&](const string& a, const string& b) {
      return a + b > b + a;
    });

    string res;
    for (auto& s : arr) {
      res += s;
    }

    int i = 0;
    while (i != res.size() - 1 && res[i] == '0') {
      ++i;
    }

    return res.substr(i);
  }
};
