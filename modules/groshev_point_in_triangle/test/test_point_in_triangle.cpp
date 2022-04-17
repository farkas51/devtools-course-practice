#include <gtest/gtest.h>
#include <tuple>
#include <string>

#include "include/point_in_triangle.h"


TEST(PointConstructor, ConstructorWithoutParameters) {
  ASSERT_NO_THROW(Point());
}

TEST(TriangleConstructor, ConstructorWithoutParameters) {
  ASSERT_NO_THROW(Triangle());
}