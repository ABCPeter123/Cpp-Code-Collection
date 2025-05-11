#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        temp.push_back(t);
        if (t == 1) {
            cnt1++;
            if (i != 0 && temp[i - 1] == 1) cnt2++;
        }
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            cnt1++;
            if (i != 0 && temp[i - 1] == 1) cnt2++;
            if (i % 2 == 0 && temp[i] == 1) cnt2++;
        }
        temp[i] = t;
    }
    cout << 3 * cnt1 - 2 * cnt2;
}

/**
0 1 1 1 0 1 1
0 1 1 0 1 0 1

24 - 10

 */