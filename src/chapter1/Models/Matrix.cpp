#ifndef MATRIX_H
#define MATRIX_H

// For the matrix class, add a resize member function and zero-parameter
// constructor

#include <array>
#include <iostream>
#include <vector>
using namespace std;
template <typename Object> class Matrix {
public:
  Matrix(int rows, int cols) : array(rows) {
    for (auto &thisRow : array) {
      thisRow.resize(cols);
    }
  }
  Matrix() {}

  explicit Matrix(vector<vector<Object>> v) : array{v} {}

  explicit Matrix(vector<vector<Object>> &&v) : array{std::move(v)} {}
  // accessor
  const vector<Object> &operator[](int row) const { return array[row]; }

  vector<Object> &operator[](int row) { return array[row]; }

  int numRows() const { return array.size(); }
  int numCols() const { return numRows() ? array[0].size() : 0; }

  void resize(int newSize) {
    array.resize(newSize);
    for (auto &cols : array) {
      cols.resize(newSize);
    }
  }

  void display() {
    for (int i = 0; i < array.size(); i++) {
      for (int j = 0; j < array.size(); j++) {
        cout << array[i][j] << " ";
      }
      cout << endl;
    }
  }

private:
  vector<vector<Object>> array;
};
#endif
