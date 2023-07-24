#include <iostream>
using namespace std;

int main() {
    int n, r, s, d;
    string name;
    cin >> n;
    if (n > 0) {
        cin >> name >> r >> s >> d;
        int value = 2 * r + 3 * s + d;
        int best1 = value;
        int best2 = 0;
        string bestname1 = name;
        string bestname2 = "";
        for (int i = 1; i < n; i++) {
            cin >> name >> r >> s >> d;
            value = 2 * r + 3 * s + d;
            if (value > best1 || (value == best1 && name < bestname1)) {
                best2 = best1;
                bestname2 = bestname1;
                best1 = value;
                bestname1 = name;
            } else if (value > best2 || (value == best2 && name < bestname2)) {
                best2 = value;
                bestname2 = name;
            }
        }

        if (n == 1) cout << bestname1 <<endl;
        else {
            cout << bestname1 <<endl;
            cout << bestname2 <<endl;
        }
    }
    return 0;
}