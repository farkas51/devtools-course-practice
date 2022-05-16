#include <string>
#include <vector>
#include "include/remizova_a_matrix.h"
#ifndef MODULES_REMIZOVA_MATRIX_INCLUDE_REMIZOVA_A_APPLICATION_H_
#define MODULES_REMIZOVA_MATRIX_INCLUDE_REMIZOVA_A_APPLICATION_H_


class MatrixCalculator {
 public:
  MatrixCalculator();
  std::string operator()(int argc, const char** argv);

 private:
  void helpMessage(const char* message);
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;

};
#endif  // MODULES_REMIZOVA_MATRIX_INCLUDE_REMIZOVA_A_APPLICATION_H_
