/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-hashset/
 * Runtime: 103ms
 */

class MyHashSet {
#define BUCKET_SIZE 10007
  
private: 
  list<int>* hash;

  list<int>::iterator find(list<int>& l, int key) const {
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
      if (*it == key) {
        return it;
      }
    }

    return l.end();
  }
public:
  MyHashSet() {
    hash = new list<int>[BUCKET_SIZE];
  }

  ~MyHashSet() {
    delete[] hash;
  }

  void add(int key) {
    list<int>& l = hash[key % BUCKET_SIZE];
    list<int>::iterator it = find(l, key);

    if (it == l.end()) {
      l.emplace_back(key);
    }
  }

  void remove(int key) {
    list<int>& l = hash[key % BUCKET_SIZE];
    list<int>::iterator it = find(l, key);

    if (it != l.end()) {
      l.erase(it);
    }
  }

  bool contains(int key) {
    list<int>& l = hash[key % BUCKET_SIZE];
    list<int>::iterator it = find(l, key);

    return (it != l.end());
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
