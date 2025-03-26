#include "Models/IntCell.h"
#include <iostream>
#include <ostream>


int main() {
  IntCell m;
  m.write(5);
  std::cout << "Cell contents: " << m.read() << std::endl;
}
