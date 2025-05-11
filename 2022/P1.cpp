#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    while (((n - 5 * i) % 4 != 0) && (n >= 5 * i)) i++;
    if (n < 5 * i) {
        cout << "0" << endl;
    } else {
        int max = floor(n / 5);
        cout << floor((max - i) / 4) + 1 << endl;
    }
}