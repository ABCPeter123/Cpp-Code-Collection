#include <iostream>
#include <string>
using namespace std;

void rabin_karp(string text, string pattern) {
    int pat_hash = 0;
    int txt_hash = 0;
    int n = text.length();
    int m = pattern.length();
    int q = INT_MAX;
    int d = 256;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        pat_hash = (d * pat_hash + pattern[i]) % q;
        txt_hash = (d * txt_hash + text[i]) % q;
    }

    for (int i = 0; i < n - m; i++) {
        if (pat_hash == txt_hash) {
            int j = 0;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == m) cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m) {
            txt_hash = (d * (txt_hash - text[i] * h) + text[i + m]) % q;
 
            if (txt_hash < 0) txt_hash = (txt_hash + q);
        }
    }
    
}

// int main() {
//     rabin_karp("AABAABAABBA", "AABA");
// }