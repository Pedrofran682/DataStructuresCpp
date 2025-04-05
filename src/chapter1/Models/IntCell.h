#ifndef IntCell_H
#define IntCell_H

class IntCell {
public:
  explicit IntCell(int initialValue = 0);
  // Accessor - const keyword after '(' 
  int read() const;
  void write(int x);

private:
  int storedValue;
};

#endif
