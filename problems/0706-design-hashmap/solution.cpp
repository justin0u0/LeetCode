/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-hashmap/
 * Runtime: 131ms
 */

class MyHashMap {
#define BUCKET_SIZE 10007

private:
  list<pair<int, int>>* hm;

  list<pair<int, int>>::iterator find(list<pair<int, int>>& l, int key) {
    for (list<pair<int, int>>::iterator it = l.begin(); it != l.end(); ++it) {
      if (it->first == key) {
        return it;
      }
    }

    return l.end();
  }
public:
  MyHashMap() {
    hm = new list<pair<int, int>>[BUCKET_SIZE];
  }

  ~MyHashMap() {
    delete[] hm;
  }

  void put(int key, int value) {
    list<pair<int, int>>& l = hm[key % BUCKET_SIZE];
    list<pair<int, int>>::iterator it = find(l, key);

    if (it == l.end()) {
      l.emplace_back(key, value);
    } else {
      it->second = value;
    }
  }

  int get(int key) {
    list<pair<int, int>>& l = hm[key % BUCKET_SIZE];
    list<pair<int, int>>::iterator it = find(l, key);

    if (it == l.end()) {
      return -1;
    }

    return it->second;
  }

  void remove(int key) {
    list<pair<int, int>>& l = hm[key % BUCKET_SIZE];
    list<pair<int, int>>::iterator it = find(l, key);

    if (it != l.end()) {
      l.erase(it);
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
