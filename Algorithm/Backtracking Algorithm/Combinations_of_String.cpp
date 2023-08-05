#include <iostream>
#include <string>
using namespace std;

void permute(string s, int left, int right) {
    if (left == right) cout << s << endl;
    else {
        for (int i = left; i <= right; i++) {
            swap(s[i], s[left]);
            permute(s, left + 1, right);
            swap(s[i], s[left]);
        }
    }
    
}

// int main() {
//     permute("ABC", 0, 2);
// }