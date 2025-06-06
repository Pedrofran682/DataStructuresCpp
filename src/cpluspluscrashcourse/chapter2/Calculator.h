#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Operation.h"
#include <exception>
#include <stdexcept>

struct Calculator {
  Operation operation;
  Calculator(Operation operation) : operation(operation) {}

  int calculate(double a, double b) {
    double result;
    switch (operation) {
    case (Operation::Add): {
      result = {a + b};
    } break;
    case (Operation::Subtract): {
      result = {a - b};
    } break;
    case (Operation::Multiply): {
      result = {a * b};
    } break;
    case (Operation::Divide): {
      result = {a / b};
    } break;
    default: {
      throw std::runtime_error("Unsupported operation");
    }
    }
    return result;
  };
};
#endif
