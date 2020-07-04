#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

template <class T>
T sum(vector<T> d, int size, T res = 0) {
    
    for (int i = 0; i < size; ++i) {
        res += d[i];
    }

    return res;
}

int main() {
    const int size = 4;
    vector<int> d1;

    for (int i = 0; i < size; ++i) {
        d1.push_back(i);
    }

    cout << sum(d1, size) << endl;

    return 0;
}
