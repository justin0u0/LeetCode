/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lfu-cache/
 * Runtime: 500ms (92.42%)
 */

class LFUCache {
private:
  int size;
  int capacity;
  int minFrequency;

  struct Value {
    int value;
    int frequency;
    list<int>::const_iterator it;
  };
  unordered_map<int, Value> m;
  unordered_map<int, list<int>> ml;

  void use(unordered_map<int, Value>::iterator it) {
    int key = it->first;
    Value& v = it->second;

    auto& lold = ml.at(v.frequency);
    lold.erase(v.it);
    if (v.frequency == minFrequency && lold.empty()) {
      ++minFrequency;
    }
    ++v.frequency;

    auto& lnew = ml[v.frequency];
    lnew.emplace_front(key);
    v.it = lnew.cbegin();
  }
public:
  LFUCache(int capacity) : size(0), capacity(capacity) {}
  
  int get(int key) {
    auto it = m.find(key);
    if (it == m.end()) {
      return -1;
    }

    use(it);
    return it->second.value;
  }
  
  void put(int key, int value) {
    if (capacity == 0) {
      return;
    }

    auto it = m.find(key);
    if (it != m.end()) {
      it->second.value = value;
      return use(it);
    }

    if (size == capacity) {
      auto& l = ml.at(minFrequency);
      int vk = l.back();
      l.pop_back();
      m.erase(vk);
    } else {
      ++size;
    }

    minFrequency = 1;
    auto& l = ml[1];
    l.emplace_front(key);
    m.emplace(key, Value{value, 1, l.cbegin()});
  }
};
