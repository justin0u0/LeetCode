/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/insert-delete-getrandom-o1/
 * Runtime: 232ms (95.22%)
 */

class RandomizedSet {
private:
  unordered_map<int, int> m;
  vector<int> arr;
public:
  RandomizedSet() {}

  bool insert(int val) {
    const auto& [_, inserted] = m.emplace(val, arr.size());
    if (!inserted) {
      return false;
    }

    arr.emplace_back(val);
    return true;
  }

  bool remove(int val) {
    const auto& it = m.find(val);
    if (it == m.end()) {
      return false;
    }

    if (arr.size() > 1) {
      arr[it->second] = arr.back();
      m.at(arr.back()) = it->second;
    }
    arr.pop_back();
    m.erase(it);

    return true;
  }

  int getRandom() {
    return arr[rand() % arr.size()];
  }
};
