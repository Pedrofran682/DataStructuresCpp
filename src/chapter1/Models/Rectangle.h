#ifndef rectangle_h
#define rectangle_h

class Rectangle {
public:
  Rectangle(double width, double lenght);
  // All accessor must have the const keyword
  double getWidth() const;
  double getLength() const;

private:
  double lenght;
  double width;
};
#endif
