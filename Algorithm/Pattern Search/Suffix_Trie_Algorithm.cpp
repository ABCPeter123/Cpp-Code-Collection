#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_CHAR 256

class SuffixTrieNode {
    SuffixTrieNode *children[MAX_CHAR];
    vector<int> indexes;

public:
    SuffixTrieNode() {
        for (int i = 0; i < MAX_CHAR; i++) {
            children[i] = NULL;
        }
    }

    void insertSuffix(string s, int index) {
        indexes.push_back(index);

        if (s.length() > 0) {
            char child_index = s.at(0);

            if (children[child_index] == NULL) children[child_index] = new SuffixTrieNode();

            children[child_index] -> insertSuffix(s.substr(1), index + 1);
        }
    }

    vector<int> search(string pattern) {
        if (pattern.length() == 0) {
            return indexes;
        }

        if (children[pattern.at(0)] != NULL) {
            return (children[pattern.at(0)] -> search(pattern.substr(1)));
        }
        else return {-1};
    }
};

class SuffixTrie {
    SuffixTrieNode root;

public:
    SuffixTrie(string text) {
        for (int i = 0; i < text.length(); i++) {
            root.insertSuffix(text.substr(i), i);
        }
    }

    void search(string pattern) {
        vector<int> result = root.search(pattern);
        if (result[0] == -1) {
            cout << "Pattern not found!" << endl;
        }
        else {
            for (auto i : result) {
                cout << "The result is found at " << i - pattern.length() << endl;
            }
        }
    }   
};

int main() {
    string text = "AABAABAABBA";
    SuffixTrie S(text);
    S.search("AABA");
}