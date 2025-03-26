#include "IntCell.h"

// class IntCell {
// public:
//   explicit IntCell(int initialValue = 0) : storedValue{initialValue} {}
IntCell::IntCell(int initialValue) : storedValue{initialValue} {}
//   int read() { return storedValue; }
//   void write(int x) { storedValue = x; }
// private:
// //   int storedValue;
// };
int IntCell::read() const { return storedValue; }
void IntCell::write(int x) { storedValue = x; }
