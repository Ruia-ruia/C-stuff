#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef enum days{SUN, MON, TUES, WEDS, THURS, FRI, SAT} days;

inline days operator++ (days d) {
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

inline days operator-- (days d) {
    return static_cast<days>((static_cast<int>(d) + 6) % 7);
}

int main() {
    cout << --SAT << endl;
    cout << ++SAT << endl;

    return 0;
}
