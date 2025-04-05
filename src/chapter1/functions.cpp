#include "Models/IntCell.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

void printDigit(int n) { std::cout << n; }

void printDigit(double n) { std::cout << n; }

void printOut(int n) {
  if (n >= 10)
    printOut(n / 10);
  printDigit(n % 10);
}

void PrintIntCell() {
  IntCell m{2};
  // m.write(5);
  std::cout << "Cell contents: " << m.read() << std::endl;
}

void DefineVectors() {
  std::vector<int> squares(100); // Vector of size 100
  for (int index = 0; index < squares.size(); index++)
    squares[index] = index * index;

  for (auto index = 0; index < squares.size(); index++) {
    std::cout << index << " " << squares[index] << std::endl;
  }
}

void PrintPointerIntCell() {
  // C++ do not check with m has a value or not. It must have a nullpoint or a
  // prior validation
  IntCell *m = nullptr;
  // new keyword return a pointer
  m = new IntCell{0};
  m->write(5);
  std::cout << "Cell contents: " << m->read() << std::endl;
  delete m;
}

void badSwap(std::vector<int> &x, std::vector<int> &y) {
  auto tmp = x;
  x = y;
  y = tmp;
}

void Swap(std::vector<int> &x, std::vector<int> &y) {
  auto tmp = std::move(x);
  x = std::move(y);
  y = std::move(tmp);
}

void permute(const std::string &str, int low, int high) {
  // To be able to use swap, we must create a copy non const
  auto tempString = str;
  std::cout << tempString << std::endl;
  if (low != high) {
    for (auto index = low; index <= high; index++) {
      std::swap(tempString[low], tempString[high]);
      // Here we fix the high index and move only the low index.
      permute(tempString, ++low, high);
      // Then we switch back the letters for the next iteration
      std::swap(tempString[high], tempString[low]);
    }
  }
}

void permute(const std::string &str) {
  auto low = 0;
  auto high = str.length() - 1;
  permute(str, low, high);
}
