#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char choices[n];
    char answers[n];
    for (int i = 0; i < n; i++) {
        char input;
        cin >> input;
        choices[i] = input;
    }
    for (int i = 0; i < n; i++) {
        char input;
        cin >> input;
        answers[i] = input;
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (choices[i] == answers[i]) {
            counter++;
        }
    }
    cout << counter;
    return 0;
}