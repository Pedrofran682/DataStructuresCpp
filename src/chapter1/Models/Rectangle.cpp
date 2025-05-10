// Define a Rectangle class that provides getLength and getWidth. Using the
// findMax routines in Figure 1.25, write a main that creates an array of
// Rectangle and finds the largest Rectangle first on the basis of area and then
// on the basis of perimeter.

#include "Rectangle.h"

Rectangle::Rectangle(double width, double lenght)
    : width{width}, lenght{lenght} {}

double Rectangle::getWidth() const { return width; }

double Rectangle::getLength() const { return lenght; }
