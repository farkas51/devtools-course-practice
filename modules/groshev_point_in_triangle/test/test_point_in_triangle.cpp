#include <gtest/gtest.h>
#include <tuple>
#include <string>

#include "include/point_in_triangle.h"


TEST(PointConstructor, Constructor_Without_Parameters) {
  ASSERT_NO_THROW(Point());
}

TEST(PointConstructor, Constructor_With_Parameters) {
  ASSERT_NO_THROW(Point(5.0,2.0));
}

TEST(PointConstructor, Get_Coordinates_From_Default_Point) {
  // Arrange
  Point t;
  
  // Act & Assert
  ASSERT_TRUE((t.x == 0) && (t.y == 0));
}

TEST(PointConstructor, Get_Coordinates_From_Point) {
  // Arrange
  Point t(5.0,2.0);

  // Act & Assert
  ASSERT_TRUE((t.x == 5.0) && (t.y == 2.0));
}


TEST(TriangleConstructor, Constructor_Without_Parameters) {
  ASSERT_NO_THROW(Triangle());
}


TEST(TriangleConstructor, Constructor_With_Parameters) {
  // Arrange
  Point a(-3.0, 0.0);
  Point b(3.0, 0.0);
  Point c(0.0, 3.0);

  // Act & Assert
  ASSERT_NO_THROW(Triangle(a,b,c));
}



TEST(TrianglesTest, Throws_when_incorrect_points) {
  // Arrange
  Point a(1.0, 2.0);
  Point b(3.0, 4.0);
  Point c(5.0, 6.0);

  // Act & Assert
  ASSERT_ANY_THROW(Triangle (a, b, c));
}

