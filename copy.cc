#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

template <class T1, class T2>
void copy(const T1 source[], T2 destination[], int size) {

    for (int i = 0; i < size; ++i) {
        destination[i] = static_cast<T2>(source[i]);
    }

}

int main(){
    int size = 5;
    int* d1 = new int[size];
    int* d2 = new int[size];

    for (int i = 0; i < size; ++i) {
        d1[i] = 2 * i;
        d2[i] = 3 * i;
    }

    copy(d1, d2, size);

    return 0;
}
