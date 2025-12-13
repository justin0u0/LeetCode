/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/coupon-code-validator/
 * Runtime: 3ms (81.55%)
 */

class Solution {
public:
  vector<string> validateCoupons(const vector<string>& code, const vector<string>& businessLine, const vector<bool>& isActive) {
    const int n = code.size();

    auto validCode = [](const string& s) {
      if (s.empty()) {
        return false;
      }
      for (const char c : s) {
        if (!(
          (c >= '0' && c <= '9') ||
          (c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c == '_')
        )) {
          return false;
        }
      }
      return true;
    };

    unordered_map<string, int> order{
      {"electronics", 1},
      {"grocery", 2},
      {"pharmacy", 3},
      {"restaurant", 4}
    };

    vector<pair<int, string>> coupons;
    for (int i = 0; i < n; ++i) {
      const auto& c = code[i];
      const auto& b = businessLine[i];
      if (isActive[i] && validCode(c) && order.count(b) != 0) {
        coupons.push_back({order[b], c});
      }
    }
    sort(coupons.begin(), coupons.end());

    vector<string> sorted;
    for (const auto& [_, s] : coupons) {
      sorted.emplace_back(s);
    }
    return sorted;
  }
};
