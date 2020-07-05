#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

typedef enum days{SUN, MON, TUES, WEDS, THURS, FRI, SAT} days;

inline days operator++ (days d) {
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

inline days operator-- (days d) {
    return static_cast<days>((static_cast<int>(d) + 6) % 7);
}

ostream& operator<< (ostream& out, const days& d) {
    switch(d) {
        case SUN: out << "SUN"; break;
        case MON: out << "MON"; break;
        case TUES: out << "TUES"; break;
        case WEDS: out << "WEDS"; break;
        case THURS: out << "THURS"; break;
        case FRI: out << "FRI"; break;
        case SAT: out << "SAT"; break;
    }

    return out;
}

int main() {
    cout << --SAT << endl;
    cout << ++SAT << endl;

    return 0;
}
