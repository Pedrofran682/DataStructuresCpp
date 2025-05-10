#ifndef COLLECTION_H
#define COLLECTION_H

// Design a class template, Collection, that stores a collection of Objects (in
// an array), along with the current size of the collection. Provide public
// functions isEmpty, makeEmpty, insert, remove, and contains. contains(x)
// returns true if and only if an Object that is equal to x is present in the
// collection.
//
#include <vector>
template <typename Object> class Collection {
public:
  // If the constructor has only one parameter we must use the explicit keyword
  explicit Collection(const int collectionSize, std::vector<Object> vector)
      : collectionSize{collectionSize}, objects{vector} {}

  bool isEmpty() { return objects.empty(); }

  void insert(Object newObject) { objects.insert(newObject); }

  void remove(int index) { objects.erase(index); }

  void erase() { objects.erase(objects.begin(), objects.begin() + objects.size()); }

  bool operator==(const Collection<Object> otherObject) {
    for (auto index = 0; index < objects.size(); index++) {
      if (objects[index] != otherObject.objects[index])
        return false;
    }
    return true;
  }
  std::vector<Object> objects;
  int collectionSize;
};
#endif
