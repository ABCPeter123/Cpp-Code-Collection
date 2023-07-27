#include <iostream>
#include <vector>
using namespace std;

int multiplication(vector<int> array, int head, int tail) {
    if (head == tail) return 0;
    int minimum = INT_MAX;
    int count = 0;
    for (int sep = head; sep < tail; sep++) {
        count = array[head - 1] * array[sep] * array[tail] + multiplication(array, head, sep) + multiplication(array, sep + 1, tail);
        minimum = min(minimum, count);
    }

    return minimum;
}

// int main() {
//     vector<int> array = {1, 2, 3, 4, 3};
//     cout << multiplication(array, 1, 4);
// }