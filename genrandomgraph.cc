#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//Cardinality of node set
//for the randomly generated graph
const int size = 10;

class node {
  public:
    node(int id):id(id){};

    void add_neighbour(int neigh, int weight) {
      vector<int> v;
      v.push_back(neigh);
      v.push_back(weight);
      neighbours.push_back(v); };

    void print_neighbours();

  private:
    int id;
    vector< vector<int> > neighbours;
};
void node::print_neighbours() {
    for (int i = 0; i < neighbours.size(); ++i) {
        cout << neighbours[i][0] << endl;
    }
}

class graph {
  public:
    void add_node(int id) {
      nodes.push_back(node(id)); }

    void add_edge(int id1, int id2, int weight) {
      nodes[id1].add_neighbour(id2, weight);
        nodes[id2].add_neighbour(id1, weight); }

    void print_neighbours_of(int id) {
      nodes[id].print_neighbours(); }

  private:
    vector<node> nodes;
};

//Generate random graph and return reference
graph& gen_graph(graph& new_g) {
    bool** matrix;
    srand(time(0));

    //allocate space for 2D matrix
    matrix = new bool * [size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new bool[size];
    }

    //initialise boolean connectivity matrix
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i == j) matrix[i][j] = false;
            else matrix[i][j] =
                 matrix[j][i] = ((static_cast<float>(rand())
                              / static_cast<float>(RAND_MAX))
                              < 0.19);
        }
    }

    //generate actual graph with nodes
    //each node with an adjacency list
    for (int i = 0; i < size; ++i) {
        new_g.add_node(i);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (matrix[i][j]) {
                int weight = static_cast<int>(rand())
                           / static_cast<int>(RAND_MAX);

                new_g.add_edge(i, j, weight);
            }
        }
    }

    return new_g;
}


int main() {
    graph g;
    g = gen_graph(g);

    for (int i = 0; i < size; ++i) {
        g.print_neighbours_of(i);
        cout << "----" << endl;
    }
}