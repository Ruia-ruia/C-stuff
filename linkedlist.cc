/* small beginnings for linked list implementation in C++ */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;

class slist {
    
  struct slistelem {
      char *data;
      slistelem *next;
  };

  public:
    slist():h(0){};         //empty list      -- pointing to 0
    ~slist(); //destructor      -- return every element back to system

    void prepend(char*);
    void print_h() { cout << h -> data << endl; }
    void print_next() { cout << n -> data << endl; n = n -> next; }

  private:
    void release();
    slistelem *h;
    slistelem *n;
};

slist::~slist() {
    cout << "Destructor invoked" << endl;
    release();
}

void slist::release() {
    while (h) {
        delete h;
        h = h -> next;
    }
}

//we use the :: as a scope resolution for the method definition
void slist::prepend(char* c) {
    slistelem *temp = new slistelem;      //from the heap
    temp -> next = h;
    temp -> data = c;
    h = temp;
    n = h;
}

int main() {
    slist my_slist;

    char *a = "data";
    char *b = "wow";
    char *c = "ok";

//we call the methods with the dot operator
    my_slist.prepend(a);
    my_slist.prepend(b);
    my_slist.prepend(c);

    my_slist.print_next();
    my_slist.print_next();
    my_slist.print_next();
}
