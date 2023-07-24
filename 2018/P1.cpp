#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> villages;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        villages.push_back(x);
    }
    sort(villages.begin(), villages.end());
    double min = (villages[2] - villages[0]) / 2.0;
    for (int i = 2; i < n - 1; i++) {
        double min_temp = (villages[i + 1] - villages[i - 1]) / 2.0;
        if (min_temp < min) min = min_temp;
    }
    cout << fixed << setprecision(1) << min << endl;
}