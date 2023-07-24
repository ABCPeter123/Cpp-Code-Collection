#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

        Node() {
            this -> data = 0;
            this -> next = NULL;
        }

        void insert(int data) {
            Node* temp1 = new Node();
            temp1 -> data = data;
            Node* temp2 = this;
            while (temp2 -> next != NULL) temp2 = temp2 -> next;
            temp2 -> next = temp1;
        }
};

Node* list[1000001];

bool find(Node* head, int n) {
    Node* temp = head;
    if (temp == NULL) return false;
    if (temp -> next == NULL) return false;
    while ((temp -> next) != NULL) {
        temp = temp -> next;
        if ((temp -> data) == n) return true;
    }
    temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
        if (find(list[(temp -> data)], n)) return true;
    }
    return false;
}

int main() {
    int people, comparison;
    cin >> people >> comparison;
    for (int i = 1; i <= comparison; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        if (list[n1] == NULL) {list[n1] = new Node();}
        list[n1] -> insert(n2);
    }
    int a, b;
    cin >> a >> b;
    if (find(list[a], b)) cout << "yes" << endl;
    else if(find(list[b], a)) cout << "no" << endl;
    else cout << "unknown" << endl;
}