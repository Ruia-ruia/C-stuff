#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

template <typename T>
inline void swap(T& d, T& s) {
    T temp = d;
    d = s;
    s = temp;
}


int main(void) {
    int a = 3;
    int b = 2;

    swap(a, b);

    cout << a << " " << b << endl;

    double c = 3.0;
    double d = 2.5;

    swap(c, d);

    cout << c << " " << d << endl;

    return 0;
}
