#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>

using namespace std;

int main() {
    int cnt = 0;
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                for (int d = 0; d <= 9; d++) {
                    if (1001 * a + 110 * b <= 1001 * c + 110 * d) continue;
                    if ((1001 * a + 110 * b - 1001 * c - 110 * d) % 35 == 0) {
                        cout << 1001 * a + 110 * b << " " << 1001 * c + 110 * d << endl;
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}
