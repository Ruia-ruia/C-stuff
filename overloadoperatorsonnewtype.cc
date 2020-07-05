#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;

class point {
  public:
    double getx() { return x; }
    void setx(double v) { x = v; }

    double gety() { return y; }
    void sety(double v) { y = v; }

    double x, y;
};

point operator+ (const point& p, const point& q) {
    point sum = { p.x + q.x, p.y + q.y };
    return sum;
}

ostream& operator<< (ostream& out, const point& p) {
    out << "( " << p.x << ", " << p.y << " )";
    return out;
}

int main() {
    point p = { 1.2, 3.5 };
    point q = { 2.3, 3.4 };

    cout << (p + q) << endl;

    return 0;
}
