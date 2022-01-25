/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-mountain-array/
 * Runtime: 48ms
 */

class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    int n = (int)arr.size();

    if (n < 3) {
      return false;
    }

    vector<int>::iterator pre = arr.begin();
    vector<int>::iterator cur = next(pre);

    while (cur != arr.end() && (*pre) < (*cur)) {
      ++pre;
      ++cur;
    }
    if (pre == arr.begin() || cur == arr.end()) {
      return false;
    }

    while (cur != arr.end() && (*pre) > (*cur)) {
      ++pre;
      ++cur;
    }

    return (cur == arr.end());
  }
};
