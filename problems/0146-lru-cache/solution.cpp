/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lru-cache/
 * Runtime: 437ms (98.53%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class LRUCache {
private:
  int capacity;
  list<int> l;
  unordered_map<int, pair<int, list<int>::iterator>> m;

  void use(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
    l.erase(it->second.second);
    l.emplace_front(it->first);
    it->second.second = l.begin();
  }
public:
  LRUCache(int capacity) : capacity(capacity) {}
  
  int get(int key) {
    auto it = m.find(key);
    if (it != m.end()) {
      use(it);
      return it->second.first;
    }
    return -1;
  }
  
  void put(int key, int value) {
    auto it = m.find(key);
    if (it != m.end()) {
      it->second.first = value;
      use(it);
      return;
    }

    if (m.size() == capacity) {
      m.erase(l.back());
      l.pop_back();
    }
    l.emplace_front(key);
    m.emplace(key, pair{value, l.begin()});
  }
};
