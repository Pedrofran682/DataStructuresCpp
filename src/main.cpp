#include "chapter1/Models/Collection.h"
#include "chapter1/Models/Rectangle.h"
#include "chapter1/Models/Utils/FindMax.h"
#include "chapter1/functions.cpp"
#include <ostream>
#include <vector>
#include "chapter1/Models/Matrix.cpp"

int main() {
  // printOut(20);
  // printDigit(3.14);
  // permute("abc");
  //
  //
  // auto myVector = std::vector<std::string>{"Hello"};
  // auto myCollection = Collection<std::string>{1, myVector};
  // auto myVector2 = std::vector<std::string>{"World"};
  // auto myCollection2 = Collection<std::string>{1, myVector};
  // std::cout << myCollection.objects[0] << std::endl;
  // auto boolTest = myCollection == myCollection2;
  // std::cout << boolTest << std::endl;
  // myCollection.erase();
  // std::cout << myCollection.isEmpty() << std::endl;
  //
  //
  // auto myRectangles = std::vector<Rectangle>{Rectangle(2, 4), Rectangle(8, 1)};
  // std::cout << "Max length: "
  //           << findMax(myRectangles, LengthCompare{}).getLength() << std::endl;
  // std::cout << "Max width: " << findMax(myRectangles, WidthCompare{}).getWidth()
  //           << std::endl;
  //
  // auto matrix = Matrix<int>(10,10);
  //
  auto matrix = Matrix<int>();
  matrix.display();
  matrix.resize(5);

  matrix.display();
  return 0;
}
