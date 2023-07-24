#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t_counter = 0;
    int s_counter = 0;
    string sentence;
    getline(cin, sentence);
    for (int i = 1; i <= n; i++) {
        getline(cin, sentence);
        for (int j = 0; j < sentence.length(); j++) {
            if (sentence[j] == 't' || sentence[j] == 'T')  t_counter++; 
            else if (sentence[j] == 'S' || sentence[j] == 's') s_counter++;
        }
    }
    if (t_counter <= s_counter) {
        cout << "French" << endl;
    } else {cout << "English" << endl;}
    
    return 0;
}