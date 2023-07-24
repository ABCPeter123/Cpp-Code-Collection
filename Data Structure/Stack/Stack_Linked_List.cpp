#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

    public: 
        void push(Node* &top, int data) {
            Node* temp1 = new Node();
            temp1 -> data = data;
            temp1 -> next = top;
            top = temp1;
        }

        void print(Node* top) {
            if (top == NULL) return;
            print(top -> next);
            cout << top -> data << " ";
        }

        int pop(Node* &top) {
            if (top == NULL) {
                cout << "Empty stack!" << endl;
                return NULL;
            }
            Node* temp1 = top;
            int value = temp1 -> data;
            top = top -> next;
            temp1 = NULL;
            return value;
        }

        Node* reverse(Node* top) { // using stack to reverse linked list
            Node* temp1 = top;
            Node* temp2 = NULL;
            while (temp1 != NULL) {
                temp2 -> push(temp2, temp1 -> pop(top));
                temp1 = temp1 -> next;
            }
            return temp2;
        }
};

int main() {
    Node* top = NULL;
    top -> pop(top);
    top -> push(top, 1);
    top -> push(top, 2);
    top -> push(top, 3);
    top -> push(top, 4);
    top -> push(top, 5);
    top -> push(top, 6);
    top -> push(top, 7);
    top -> push(top, 8);

    cout << "List is: ";
    top -> print(top);
    cout << endl;
    top -> pop(top);
    cout << "List is: ";
    top -> print(top);
    cout << endl;
    top = top -> reverse(top);
    cout << "List is: ";
    top -> print(top);
    cout << endl;
}