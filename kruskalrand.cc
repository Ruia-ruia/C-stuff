#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

double prob() {
    return (static_cast<double>(rand())/RAND_MAX);
}

void make_graph(bool**& graph, int**& cost, int size, double density) {
//first arg is reference to double pointers

    srand(time(0));

    //allocating three 2D matrices on the heap
    graph = new bool* [size];
    cost = new int* [size];

    for (int i = 0; i < size; ++i) {
          graph[i] = new bool[size];
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
                cost[i][j] = cost[j][i] = prob() * 30;
            }
        }
    }
}

double get_graph_density() {
    double density;
    cout << "graph density (0, 1): ";
    cin >> density;

    return density;
}

int get_graph_size() {
    int size;
    cout << "Graph size: ";
    cin >> size;

    return size;
}

int main() {
    bool **graph;
    int **cost;
    vector<vector<int> > ascension;
    bool flag = false;

    int size = get_graph_size();
    double density = get_graph_density();
    make_graph(graph, cost, size, density);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (graph[i][j]) {
               if (ascension.size() < 1) {
                  vector<int> v;
                  v.push_back(i);
                  v.push_back(cost[i][j]);
                  v.push_back(j);
                  ascension.push_back(v);
               } else {
                    int w = 0;
                    for (auto x : ascension) {
                        if (x[1] < cost[i][j]) {
                            vector<int> v;
                            v.push_back(i);
                            v.push_back(cost[i][j]);
                            v.push_back(j);
                            ascension.insert(ascension.begin() + w, v);

                            flag = true;
                            break;
                        }
                        w += 1;
                    }

                    if (!flag) {
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(cost[i][j]);
                        v.push_back(j);
                        ascension.push_back(v);
                    }
                }
            }
        }
    }

    vector< vector<int> > forest;

    while (ascension.size() != 0 && forest.size() != size) {
        auto elem = ascension.front();
        ascension.erase(ascension.begin());

        cout << elem[0] << ' ' << elem[1] << ' ' << elem[2] << endl;

        bool within = false;
        if (forest.size() != 0) {
            for (auto v : forest) {
                if (v[0] == elem[2] || v[2] == elem[0]) {
                    within = true;
                    break;
                }
            }

            if (!within) {
                forest.push_back(elem);
            }
        } else {
            forest.push_back(elem);
        }
    }

    cout << "-----------" << endl;

    int MST = 0;
    for (auto v : forest) {
        MST += v[1];
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    }

    cout << "And the MST's cost is: " << MST << endl;
}
