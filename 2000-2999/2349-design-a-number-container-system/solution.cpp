/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-a-number-container-system/
 * Runtime: 119ms (56.56%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class NumberContainers {
private:
  unordered_map<int, int> m;
  unordered_map<int, set<int>> ms;
public:
  NumberContainers() {}

  void change(int index, int number) {
    auto it = m.find(index);
    if (it == m.end()) {
      m.emplace(index, number);
    } else {
      ms[it->second].erase(index);
      it->second = number;
    }
    ms[number].emplace(index);
  }

  int find(int number) {
    auto it = ms.find(number);
    if (it == ms.end() || it->second.empty()) {
      return -1;
    }
    return *it->second.begin();
  }
};
