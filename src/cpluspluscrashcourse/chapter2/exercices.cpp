#include "Calculator.h"
#include "Operation.h"
#include <iostream>

void Ex1() {
  std::cout << "Exercice1\nCreate an enum class Operation that has values Add, "
               "Subtract, "
               "Multiply, and Divide."
            << std::endl;
  Operation operations;
}

void Ex2() {
  std::cout << "Exercice2\n Create a struct Calculator .It should have a "
               "single constructor that takes an Operation."
            << std::endl;
}

void Ex3() {
  std::cout << "Exercice2\nCreate a method on Calculator called int "
               "calculate(int a, int b)."
               "Upon invocation, this method should perform addition, "
               "subtraction, multiplica"
               "tion, or division based on its constructor argument and return "
               "the result."
            << std::endl;

  Operation operations;
  Calculator calculator{Operation::Add};
  std::cout << "Sum " << calculator.calculate(10, 20) << std::endl;
}
