#include <iostream>
#include <vector>

using namespace std;

const int n = 40;

//sum and return elements of d
inline void sum(int& p, vector<int> d) {
    p = 0;

    for (int i = 0; i < n; ++i) {
        p = p + d[i];
    }
}

int main() {
    int accum = 0;
    vector<int> data;

    //set each value of the vector data to i(0 -> n - 1)
    for (int i = 0; i < n; ++i) {
        data.push_back(i);
    }

    //invoke sum and output result
    sum(accum, data);
    cout << "The sum is: " << accum << endl;

    return 0;
}
