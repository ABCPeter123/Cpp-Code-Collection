#include <iostream>
#include <string>
using namespace std;

void preprocess(string pattern, int* lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i != pattern.length()) {
        if (pattern[len] == pattern[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP_Search(string text, string pattern) {
    int lps[pattern.size()];
    preprocess(pattern, lps);
    int i = 0;
    int j = 0;
    while (i != text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }

        if (j == pattern.size()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }

    }
}

int main() {
    KMP_Search("AABAABAABBA", "AABA");
}