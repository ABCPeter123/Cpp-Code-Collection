#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T, N;
    cin >> T >> N;
    char seq[N];
    int ans[T];
    unordered_map<char, bool> heav;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            cin >> seq[j];
            if (heav.find(seq[j]) != heav.end()) heav[seq[j]] = true;
            else heav.insert({seq[j], false});
        }
        int j = 0;
        if (heav.at(seq[0]) == true) j = 0;
        else j = 1;
        ans[i] = true;
        for (j; j < N; j += 2) {
            if (heav.at(seq[j]) != true) {
                ans[i] = false;
                break;
            }
        }
        j = (j % 2) + 1;
        for (j; j < N; j += 2) {
            if (heav.at(seq[j]) != false) {
                ans[i] = false;
                break;
            }
        }
        heav.clear();
    }
    for (auto i : ans) {
        if (i) cout << "T\n";
        else cout << "F\n";
    }
}