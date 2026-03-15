/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fancy-sequence/
 * Runtime: 224ms (24.82%)
 */

class Fancy {
private:
  vector<pair<int, int>> arr;     // [val, cursor]
  vector<vector<int>> ops;        // ops[page][offset]: add(positive), mul(negative)
  vector<pair<int, int>> result;  // result[page]
  int cursor;

  const int pg = 320;
  const int mod = 1e9 + 7;
public:
  Fancy() : cursor(0), ops(320), result(320, {1, 0}) {}
  
  void append(const int val) {
    arr.push_back({val, cursor});
  }

  void addAll(const int inc) {
    ops[cursor / pg].emplace_back(inc);
    auto& [_, add] = result[cursor / pg];
    add = (add + inc) % mod;
    ++cursor;
  }

  void multAll(const int m) {
    ops[cursor / pg].emplace_back(-m);
    auto& [mul, add] = result[cursor / pg];
    mul = (long long)mul * m % mod;
    add = (long long)add * m % mod;
    ++cursor;
  }
  
  int getIndex(int idx) {
    if (idx >= arr.size()) {
      return -1;
    }

    auto [val, cur] = arr[idx];

    for (int i = cur % pg; i < ops[cur / pg].size(); ++i) {
      const int op = ops[cur / pg][i];
      if (op > 0) {
        val = (val + op) % mod;
      } else {
        val = (long long)val * (-op) % mod;
      }
    }
    for (int i = cur / pg + 1; i <= cursor / pg; ++i) {
      const auto [mul, add] = result[i];
      val = ((long long)val * mul % mod + add) % mod;
    }

    return val;
  }
};
