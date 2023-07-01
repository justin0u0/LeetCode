/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fair-distribution-of-cookies/
 * Runtime: 49ms (80.16%)
 */

class Solution {
private:
  bool check(const vector<int>& cookies, int k, int lim) {
    int sum = 0;
    for (const int c : cookies) {
      if (sum + c > lim) {
        --k;
        sum = c;
      } else {
        sum += c;
      }
    }

    return k > 0;
  }
public:
  int distributeCookies(vector<int>& cookies, int k) {
    sort(cookies.begin(), cookies.end());

    int l = *max_element(cookies.begin(), cookies.end());
    int r = accumulate(cookies.begin(), cookies.end(), 0);
    while (l <= r) {
      int mid = (l + r) >> 1;

      vector<int> box = cookies;
      bool ok = false;
      do {
        if (check(box, k, mid)) {
          ok = true;
        }
      } while (!ok && next_permutation(box.begin(), box.end()));

      if (ok) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return r + 1;
  }
};
