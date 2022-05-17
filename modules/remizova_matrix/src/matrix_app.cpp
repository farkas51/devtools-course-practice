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
      "      number_colunms2 number_rows2 fill_value2 operation \n" +
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
  if (argc != 7) {
    helpMessage("Should be 7 arguments!\n\n");
    return false;
  } else {
    return true;
  }
}

std::string MatrixCalculator::RunOperations(int argc, TMatrix<int> m1,
                                            TMatrix<int> m2, int operation) {
  TMatrix<int> resMatrix(2, 2);
  bool resBool;
  int resInt;
  std::ostringstream stream;
  switch (operation) {
    case '5':
      resBool = m1 == m2;
      stream << "res = ";
      stream << resBool;
      break;
    case '6':
      resBool = m1 != m2;
      stream << "res = ";
      stream << resBool;
      break;
    case '7':
      resInt = m1.determinant(m2);
      stream << "res = ";
      stream << resInt;
      break;
  }

  message_ = stream.str();
  return message_;
}



std::string MatrixCalculator::operator()(int argc, const char** argv) {
  if (validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  int mtr_1_rows = std::stoi(argv[1]);
  int mtr_1_columns = std::stoi(argv[2]);
  int mtr_1_value = std::stoi(argv[3]);
  TMatrix<int> m1(mtr_1_rows, mtr_1_columns, mtr_1_value);

  int mtr_2_rows = std::stoi(argv[4]);
  int mtr_2_columns = std::stoi(argv[5]);
  int mtr_2_value = std::stoi(argv[6]);
  TMatrix<int> m2(mtr_2_rows, mtr_2_columns, mtr_2_value);
  const char* operation = argv[6];
  int oper = parseOperation(operation);
  return RunOperations(argc, m1, m2, oper);
}
