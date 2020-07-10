#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//size of graph, max weight of edges
const int size = 10;
const int max_weight = 100;

class node;
class graph;
class priorityq;
class qelem;

class qelem {

  node* item;
  int p;

  public:
    qelem(node* it, int priority) {
        item = it;
        p = priority;
    }

    node* get_item() { return item; }
    int get_priority() { return p; }
};

class priorityq {
  public:
    void set_item(node& n, int p) {
        qelem elem(&n, p);
        bool flag = false;

        for (int i = 0; i < items.size(); ++i) {
            if(items[i].get_priority() > elem.get_priority()) {
                items.insert(items.begin() + i, elem);
                flag = true;
                break;
            }
        }

        if (!flag) {
            items.push_back(elem);
        }
    }

    node* return_head() {
        return items[0].get_item();
    }

    void print_items() {
        for (int i = 0; i < items.size(); ++i) {
            cout << items[i].get_item() << endl;
            cout << items[i].get_priority() << endl;
            cout << "-----------" << endl;
        }
    }

  private:
    vector<qelem> items;
};

class node {
  public:
    node(int id):id(id){};

    void print_neighbours();

    void add_neighbour(int neigh, int weight) {
      vector<int> v;
      v.push_back(neigh);
      v.push_back(weight);
      neighbours.push_back(v); };

    int get_weight(int id) {
        for (int i = 0; i < neighbours.size(); ++i) {
            if (neighbours[i][0] == id) {
                return neighbours[i][1];
            }
        }
        return -1;
    }

  private:
    int id;
    vector< vector<int> > neighbours;
};
void node::print_neighbours() {
    for (int i = 0; i < neighbours.size(); ++i) {
        cout << "neighbour: " << neighbours[i][0] <<
                 "| weight: " << neighbours[i][1] << endl;
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

    int get_weight(int id, int neighbour_id) {
        return nodes[id].get_weight(neighbour_id);
    }

    node& resolve_node(int id) {
        return nodes[id];
    }

    vector<int> dijkstra();

  private:
    vector<node> nodes;
};
vector<int> graph::dijkstra() {

}


//Generate random graph from reference
void gen_graph(graph& new_g) {
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

    srand(time(0));
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (matrix[i][j]) {
                int weight = 1 + (static_cast<int>(rand()) % max_weight);
                new_g.add_edge(i, j, weight);

            }
        }
    }

    //garbage collection
    for (int i = 0; i < size; ++i) delete matrix[i];
    delete [] matrix;
}

int main() {
    graph g;
    gen_graph(g);

    priorityq pq;
    pq.set_item(g.resolve_node(0), 3);
    pq.set_item(g.resolve_node(1), 2);
    pq.set_item(g.resolve_node(3), 5);
    pq.set_item(g.resolve_node(2), 1);

    pq.print_items();

    node *n = pq.return_head();
    n -> print_neighbours();
}

