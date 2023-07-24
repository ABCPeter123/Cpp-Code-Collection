#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int mountain[5001];

int calculate(int l, int crop, int minimum) {
    int count = 0;
    int r = crop + l - 1;
    int mid = floor((l + r) / 2);
    if (crop % 2 == 1) {
        for (int left = l; left <= mid; left++) {
            count += abs(mountain[r] - mountain[left]);
            if (count >= minimum) {
                return minimum;
            }
            r--;
        }
    } else {
        for (int left = l; left <= mid; left++) {
            count += abs(mountain[r] - mountain[left]);
            if (count >= minimum) {
                return minimum;
            }
            r--;
        }
    }
    return count;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mountain[i] = a;
    }

    for (int crop = 1; crop <= n; crop++) {
        int minimum = 1000000;
        for (int l = 0; l <= n - crop; l++) {
            minimum = calculate(l, crop, minimum);
        }
        if (crop == n) {cout << minimum << endl; return 0;}
        cout << minimum << " ";
    }
}