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

  int
};

class Triangle {
 private:
  Point a, b, c;

    
 public:


};