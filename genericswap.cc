#include <iostream>
using std::cout;
using std::cin;
using std::endl;


template <class T>
T inline summation(T d[], int n) {
    T sum;

    for (int i = 0; i < n; ++i) {
        sum += d[i];
    }

    return sum;
}



int main(void) {
    double a_list[] = { 3.4, 3.5, 1.2, 5 };
    int b_list[] = { 1, 2, 3, 4 };

    cout << summation(a_list, 4) << endl;
    cout << summation(b_list, 4) << endl;
}
