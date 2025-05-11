#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    vector<int> circle;
    for (int i = 0; i < N; i++) {
        circle.push_back(1);
        cin >> circle[i];
    }
    int counter = 0;
    for (int i = 0; i < N / 2; i++) {
        if (circle[i] == circle[(i + N / 2) % N]) counter += 2;
    }
    cout << counter;
}