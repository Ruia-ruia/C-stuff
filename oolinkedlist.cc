#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class list_element {
  public:
    list_element(int n = 0, list_element *ptr = nullptr):
        d(n), next(ptr){};

    int d;
    list_element *next;
};

class list {
  public:
    list():head(nullptr), cursor(nullptr){};
    list(const list& lst);
    list(const int arr[], int size);
    ~list();

    void prepend(int n);
    int get_element(){ return cursor -> d; }
    void advance(){ cursor = cursor -> next; }
    void print();

  private:
    list_element* head;
    list_element* cursor;
};

list::~list() {
    for (cursor = head; cursor != nullptr; ) {
        cursor = head -> next;
        delete head;
        head = cursor;
    }
}

list::list(const list& lst) {
    if (lst.head == nullptr) {
        cursor = head = nullptr;
    } else {
        list_element *h = new list_element();
        list_element *previous;
        head = h;
        h -> d = lst.head -> d;
        previous = h;

        for (cursor = lst.head; cursor != nullptr; ) {
            h = new list_element();
            h -> d = cursor -> d;
            previous -> next = h;
            cursor = cursor -> next;
            previous = h;
        }
        cursor = head;
    }
}

list::list(const int arr[], int size) {
    cursor = head = new list_element(arr[0], nullptr);

    for (int i = 1; i < size; ++i) {
        list_element *c = new list_element(arr[i]);
        c -> next = head;
        head = c;
    }
}

void list::print() {
    list_element *h = head;

    while (h != nullptr) {
        cout << h -> d << ", ";
        h = h -> next;
    }

    cout << "###" << endl;
}

void list::prepend(int n) {
     if (head == nullptr) {
        cursor = head = new list_element(n, head);
     } else {
        head = new list_element(n, head);
     }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    list l;
    l.prepend(3);
    l.prepend(4);
    l.prepend(5);
    l.prepend(6);
    l.print();

    list l2(arr, 5);
    l2.print();

}
