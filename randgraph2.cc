#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;


double prob() {
    return (static_cast<double>(rand())/RAND_MAX);
}

int main() {
    int size = 15;  //default
    double density;

    cout << "Graph size: ";
    cin >> size;

    cout << "graph density (0, 1): ";
    cin >> density;

    bool **graph;
    int **colour;
    int **cost;
    srand(time(0));

    //allocating three 2D matrices on the heap
    graph = new bool* [size];
    colour = new int* [size];
    cost = new int* [size];

    for (int i = 0; i < size; ++i) {
          graph[i] = new bool[size];
          colour[i] = new int[size];
          cost[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i == j) graph[i][j] = false;
            else graph[i][j] =
                 graph[j][i] = (prob() < density);
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (graph[i][j]) {
                colour[i][j] = colour[j][i] = rand() % 3;
                cost[i][j] = cost[j][i] = prob() * 30;
            }
        }
    }

    ofstream outp("graph_data.txt");
    outp << size << "\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (graph[i][j]) {
                outp << i << '\t' << j  << '\t'
                     << cost[i][j]      << '\t'
                     << colour[i][j]    << '\n';
            }
        }
    }
}
