#include "include/point_in_triangle.h"
#include <string>




Triangle::Triangle() : a(-3.0, 0.0), b(3.0, 0.0), c(0.0, 3.0){

  ab = SideLength(a, b);
  bc = SideLength(b, c);
  ac = SideLength(a, c);

  if (!IsTriangleExist()) {
    throw std::string("Треугольник не существует");
  }
};

double Triangle::SideLength(Point _a, Point _b) {
  return sqrt(pow((_b.x - _a.x), 2) + pow((_b.y - _a.y), 2));
}

bool Triangle::IsTriangleExist() {
  return (ab + bc > ac) && (ab + ac > bc) && (bc + ac > ab) ? true : false;
}