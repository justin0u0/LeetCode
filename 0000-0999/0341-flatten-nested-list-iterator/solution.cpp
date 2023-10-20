/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flatten-nested-list-iterator/
 * Runtime: 3ms (94.83%)
 */

class NestedIterator {
private:
  stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    stk.push({nestedList.begin(), nestedList.end()});
  }

  int next() {
    auto& it = stk.top().first;
    const int res = it->getInteger();
    ++it;
    return res;
  }
  
  bool hasNext() {
    auto [it, end] = stk.top();
    if (it == end) {
      stk.pop();
      if (stk.empty()) {
        return false;
      }
      ++stk.top().first;
      return hasNext();
    }

    if (it->isInteger()) {
      return true;
    }

    auto& v = it->getList();
    stk.push({v.begin(), v.end()});
    return hasNext();
  }
};
