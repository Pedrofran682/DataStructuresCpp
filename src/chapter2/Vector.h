#include <utility>
template <typename Object> class Vector {
public:
  typedef Object *iterator;
  typedef const Object *const_iterator;
  static const int SPARE_CAPACITY = 16;

  explicit Vector(int initSize = 0)
      : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY} {
    objects = new Object[theCapacity];
  }

  Vector(const Vector &rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr} {
    objects = new Object[theCapacity];
    for (auto k = 0; k < theSize; ++k) {
      objects[k] = rhs.objects[k];
    }
  }

  ~Vector() { delete[] objects; }

  Vector(Vector &&rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity},
        objects{rhs.objects} {
    rhs.objects = nullptr;
    rhs.theSize = 0;
    rhs.theCapacity = 0;
  }

  iterator begin() { return &objects[0]; }
  const_iterator begin() const { return &objects[0]; }
  iterator end() { return &objects[size()]; }
  const_iterator end() const { return &objects[size()]; }
  // Mutator
  Object &operator[](int index) { return objects[index]; }
  // Accessor
  const Object &operator[](int index) const { return objects[index]; }
  void pop_back() { --theSize; }
  const Object &back() const { return objects[theSize - 1]; }
  bool empty() const { return size() == 0; }
  int size() const { return theSize; }
  int capacity() const { return theCapacity; }

  Vector operator=(Vector &&rhs) {
    std::swap(theCapacity, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);
    return *this;
  }

  Vector &operator=(const Vector &rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  void resize(int newSize) {
    if (newSize > theCapacity)
      reserve(newSize * 2);
    theSize = newSize;
  }

  void reserve(int newCapacity) {
    if (newCapacity < theSize)
      return;

    Object *newArray = new Object[newCapacity];
    for (auto k = 0; k < theSize; ++k)
      newArray[k] = std::move(objects[k]);

    theCapacity = newCapacity;
    std::swap(objects, newArray);
    delete[] newArray;
  }
  void push_back(const Object &x) {
    if (theSize == theCapacity)
      reserve(2 * theCapacity);
    objects[theSize++] = x;
  }

  void push_back(Object &&x) {
    if (theSize == theCapacity)
      reserve(2 * theCapacity);
    objects[theSize++] = std::move(x);
  }

private:
  int theSize;
  int theCapacity;
  Object *objects;
};
