#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    string names[k], code[k];
    for (int i = 0; i < k; i++) {
        cin>>names[i]>>code[i];
    }
    string sequence;
    cin >> sequence;
    string answer = "";
    int i = 0;
    while (i < sequence.length()) {
        for (int j = 0; j < k; j++) {
            int n = sequence.find(code[j], i);
            if (n == i) {
                answer.append(names[j]);
                i = n + (code[j].length());
                break;
            }
        }
    }
    cout << answer;
    return 0;
}