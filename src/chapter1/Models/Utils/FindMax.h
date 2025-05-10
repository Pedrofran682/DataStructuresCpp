#ifndef findmax_h
#define findmax_h

#include "../Rectangle.h"
#include <vector>
template <typename Object, typename Comparator>
const Object &findMax(const std::vector<Object> &arr, Comparator isLessThan) {
  int maxIndex = 0;
  for (auto index = 1; index < arr.size(); index++) {
    if (isLessThan(arr[maxIndex], arr[index]))
      maxIndex = index;
  }

  return arr[maxIndex];
}

class WidthCompare {
public:
  bool operator()(const Rectangle &lhs, const Rectangle &rhs) const {
    return lhs.getWidth() < rhs.getWidth();
  }
};

class LengthCompare {
public:
  bool operator()(const Rectangle &lhs, const Rectangle &rhs) const {
    return lhs.getLength() < rhs.getLength();
  }
};

// template <typename Object>
// const Object &findMax(const std::vector<Object> &arr) {
//   return findMax(arr);
// }

#endif
