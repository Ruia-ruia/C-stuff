#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> freq(26);

//increment at index normalized by 'A' = 65 --> 65 - 65 = 0
void countc(char t) {
    if (t == ' ') return;

    char ch = toupper(t);
    freq[ch - 65] += 1;
}

int main() {
    ifstream word_file("ok.txt");
    istream_iterator<char> start(word_file), end;
    vector<char> chars(start, end);

    for (auto t : chars) {
        countc(t);
    }

    //output stats
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        cout << ch << " --> " << freq[ch - 65] << endl;
    }
}
