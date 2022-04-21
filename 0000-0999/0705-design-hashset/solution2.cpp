/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-hashset/
 * Runtime: 81ms
 */

class MyHashSet {
#define BUCKET_SIZE 1000001
private:
  bitset<BUCKET_SIZE> bst;
public:
  void add(int key) {
    bst.set(key);
  }

  void remove(int key) {
    bst.reset(key);
  }

  bool contains(int key) {
    return bst.test(key);
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
