#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


bool is_connected(bool *graph[], int size) {
    int old_size = 0, c_size = 0;
    bool *close = new bool[size];           //closed set
    bool *open = new bool[size];            //open set

    for (int i = 0; i < size; ++i) {
        open[i] = close[i] = false;
    }
    open[0] = true;

    while (c_size < size) {
        for (int i = 0; i < size; ++i) {
            old_size = c_size;

            if (open[i] && (close[i] == false)) {
                close[i] = true;
                c_size++;
            }

            for (int j = 0; j < size; ++j) {
                open[j] = open[j] || graph[i][j];   //true if edge (i, j) in graph
            }
        }

        if (c_size == size) return true;
        if (old_size == c_size) return false;
    }
}

//boolean for question: whether connected or not
//this is for the connectivity matrix representation
bool** random_graph() {
    bool** graph;
    int size = 10;
    srand(time(0));

    //allocate
    graph = new bool * [size];        //create graph as 2D array
    for (int i = 0; i < size; ++i) {
        graph[i] = new bool[size];
    }

    //initialise
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i == j) graph[i][j] = false;
            else graph[i][j] = graph[j][i] = ( (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) < 0.19);     //density 1/5 times make edge
            //true or false for x -> y in the matrix
        }
    }

    return graph;
}

int main() {
    bool** g = random_graph();
    cout << is_connected(g, 10) << endl;
}
