#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//calculate number of edges of a
//complete graph, given the number
//of nodes.
inline int num_edges(int n) {
    if (n == 1)
        return n;

    return num_edges(n - 1) + n;
}


int main() {
    //number of edges per node is
    //number of nodes - 1
    int n;
    cout << "Enter the number of nodes in your graph: ";
    cin >> n;

    const int enode = n - 1;

    cout << num_edges(enode) << endl;

    return 0;
}
