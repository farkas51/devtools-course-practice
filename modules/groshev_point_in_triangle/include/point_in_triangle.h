// Copyright 2022 Groshev Nickolay


struct Point {
  double x, y; 


  explicit Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}


  Point& operator=(const Point& point) = default;

  bool operator==(const Point& point) const {
    if ((this->x == point.x) && (this->y == point.y)) {
      return true;
    } else {
      return false;
    }
  }

};

class Triangle {
 private:
  Point a, b, c;
  double ab = 0, bc = 0, ac = 0; 
    
 public:
  Triangle();
  Triangle(Point _a, Point _b, Point _c);
  double Triangle::SideLength(Point _a, Point _b);
  bool Triangle::IsTriangleExist();

  Point Triangle::get_point_a() const;
  Point Triangle::get_point_b() const;
  Point Triangle::get_point_c() const;
};