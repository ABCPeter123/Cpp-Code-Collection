// #include <iostream>
#include <string>
using namespace std;

int LPS(string sequence, int head, int tail) {
    if (head == tail) return 1;
    if (head == tail - 1 && sequence[head] == sequence[tail]) return 2;
    if (sequence[head] == sequence[tail]) return LPS(sequence, head + 1, tail - 1) + 2;
    else return max(LPS(sequence, head + 1, tail), LPS(sequence, head, tail - 1));
}

// int main() {
//     cout << LPS("BBABCBCAB", 0, 8);
// }