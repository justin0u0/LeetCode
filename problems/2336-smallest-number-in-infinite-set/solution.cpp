/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-number-in-infinite-set/
 * Runtime: 68ms (95.61%)
 */

class SmallestInfiniteSet {
private:
  int top;
  set<int> s;
public:
  SmallestInfiniteSet() : top(0) {
    s.clear();
  }
  
  int popSmallest() {
    if (s.empty()) {
      ++top;
      return top;
    }
    int res = *s.begin();
    s.erase(s.begin());
    return res;
  }
  
  void addBack(int num) {
    if (num <= top) {
      s.emplace(num);
    }
  }
};
