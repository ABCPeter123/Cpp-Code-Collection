#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
    Node* prev;
    static int size;

    public:
        void inc_size() {
            size++;
        }

        void dec_size() {
            size--;
        }

        void insert(Node* &head, int data, int n) {
            if ((n > size + 1) || (n < 1)) {
                cout << "Out of bound!" << endl;
                return;
            }
            inc_size();
            Node* temp1 = new Node();
            temp1 -> data = data;
            temp1 -> next = NULL;
            temp1 -> prev = NULL;
            if (size == 1) {
                head = temp1;
                return;
            } else if (n == 1) {
                temp1 -> next = head;
                head -> prev = temp1;
                head = temp1;
                return;
            }
            Node* temp2 = head;
            for (int i = 1; i < n - 1; i++) temp2 = temp2 -> next;
            if (size == n)  {
                temp2 -> next = temp1;
                temp1 -> prev = temp2;
                return;
            }
            
            temp1 -> next = temp2 -> next;
            (temp2 -> next) -> prev = temp1;
            temp2 -> next = temp1;
            temp1 -> prev = temp2;
        }

        void deleteNode(Node* &head, int data) {
            Node* temp1 = head;
            Node* temp2 = head -> next;
            int cnt = 0;
            while (temp2 != NULL) {
                if ((temp2 -> data) == data) {
                    cnt++; 
                    break;
                }
                temp1 = temp2;
                temp2 = temp1 -> next;
            }
            if (cnt != 0) {
                temp1 -> next = temp2 -> next; 
                (temp2 -> next) -> prev = temp1;
                dec_size();
                temp2 = NULL;
            } else {cout << "Value not found!" << endl;}
        }

        void print(Node* head) {
            Node* temp = head;
            cout << "List is: ";
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }

        void reverse_print(Node* head) {
            Node* temp = head;
            cout << "Reverse list is: ";
            while (temp -> next != NULL) temp = temp -> next;
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> prev;
            }
            cout << endl;
        }
};

int Node::size = 0;

int main() {
    Node* head = NULL;
    cout << "How many numbers to input?" << endl;
    int n, x, pos;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the number: ";
        cin >> x;
        cout << endl << "Where to input it: ";
        cin >> pos;
        head -> insert(head, x, pos);
        cout << endl;
    }
    head -> print(head);
    head -> reverse_print(head);
    
    cout << "Delete a number: ";
    cin >> x;
    cout << endl;
    head -> deleteNode(head, x);
    head -> print(head);
    head -> reverse_print(head);
}