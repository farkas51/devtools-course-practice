// Copyright 2022 Remizova Antonina & Grohev Nikolay
#include <vector>
#include <string>
#include <sstream>

#include "include/remizova_a_matrix.h"
#include "include/matrix_app.h"

MatrixCalculator::MatrixCalculator() : message_("") {}

void MatrixCalculator::helpMessage(const char* message) {
  message_ = std::string(message) +
      "      This is an application which allows you \n" +
      "      to make some operations with matrix\n" +
      "      Please provide arguments in the following format:\n" +
      "      number_colunms1 number_rows1 fill_value1 \n" +
      "      number_colunms2 number_rows2 fill_value2 \n" +
      "      Please, use integer values \n";
}
char parseOperation(const char* arg) {
  char op;
  std::string lastArgument(arg);
  if (lastArgument == "+") {
    op = '1';
  } else if (lastArgument == "-") {
    op = '2';
  } else if (lastArgument == "*") {
    op = '3';
  } else if (lastArgument == "==") {
    op = '5';
  } else if (lastArgument == "!=") {
    op = '6';
  } else if (lastArgument == "det") {
    op = '7';
  } else if (lastArgument == "T") {
    op = '8';
  } else if (lastArgument == "inv") {
    op = '9';
  } else {
    throw std::string("Wrong operation format!");
  }
  return op;
}

bool MatrixCalculator::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    helpMessage("Wrong count of arguments");
    return false;
  } else if (argc != 10 && argc != 7 && argc != 6) {
    helpMessage("Should be 6 arguments!\n\n");
    return false;
  }
  return true;
}

std::string MatrixCalculator::operator()(int argc, const char** argv) {

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }


}