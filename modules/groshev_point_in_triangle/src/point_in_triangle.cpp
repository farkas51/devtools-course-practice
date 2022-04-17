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

Triangle::Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {
  ab = SideLength(a, b);
  bc = SideLength(b, c);
  ac = SideLength(a, c);

  if (!IsTriangleExist()) {
    throw std::string("Треугольник не существует");
  }
}

double Triangle::SideLength(Point _a, Point _b) {
  return sqrt(pow((_b.x - _a.x), 2) + pow((_b.y - _a.y), 2));
}

bool Triangle::IsTriangleExist() {
  return (ab + bc > ac) && (ab + ac > bc) && (bc + ac > ab) ? true : false;
}

Point Triangle::get_point_a() const { return a; }

Point Triangle::get_point_b() const { return b; }

Point Triangle::get_point_c() const { return c; }