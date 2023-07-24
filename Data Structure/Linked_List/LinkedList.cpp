#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
    static int size;

    public: 
        void inc_size() {
            size++;
        }

        void dec_size() {
            size--;
        }

        void insert(Node* &head, int data, int n) { // insert at nth position
            if ((n > size + 1) || (n < 1)) {
                cout << "Out of bound!" << endl;
                return;
            }
            inc_size();
            Node* temp1 = new Node();
            temp1 -> data = data;
            temp1 -> next = NULL;
            if (n == 1) {
                temp1 -> next = head;
                head = temp1;
                return;
            }
            Node* temp2 = head;
            for (int i = 1; i < n - 1; i++) temp2 = temp2 -> next;
            temp1 -> next = temp2 -> next;
            temp2 -> next = temp1;
        }

        void print(Node* head) { // iterative
            Node* temp = head;
            cout << "List is: ";
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }

        /*
        void print(Node* p) { // recursive
            if (p == NULL) return;
            cout << p -> data;
            print(p -> next);
        }
        */

        void reversePrint(Node* p) { // recursive
            if (p == NULL) return;
            reversePrint(p -> next);
            cout << p -> data;
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
                dec_size();
                temp2 = NULL;
            } else {cout << "Value not found!" << endl;}
        }
        
        void reverseList(Node* &head) { // iterative
            Node* temp1 = head -> next;
            Node* temp2 = (head -> next) -> next;
            Node* temp3 = ((head -> next) -> next) -> next;
            if (temp1 == NULL) return;
            else if (temp2 == NULL) {
                temp1 -> next = head; 
                head -> next = NULL;
                head = temp1; 
                return;
            }
            else if (temp3 == NULL) {
                temp1 -> next = head;
                temp2 -> next = temp1;
                head -> next = NULL;
                head = temp2;
                return;
            }
            temp1 -> next = head;
            temp2 -> next = temp1;
            while (temp3 != NULL) {
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3 -> next;
                temp2 -> next = temp1;
            }
            head -> next = NULL;
            head = temp2;
        }
        
        /*
        void reverseList(Node* p) { // recursive, only works when there is a global Node head.   
            if (p -> next == NULL) {
                head = p;
                return;
            }
            reverseList(p -> next);
            Node* q = p -> next;
            q -> next = p;
            p -> next = NULL;
        }
        */
};

int Node::size = 0;

int main() {
    Node* head = NULL;
    cout << "How many numbers to input?" << endl;
    int n, x, pos;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter the number: ";
        cin >> x;
        cout << endl << "Where to input it: ";
        cin >> pos;
        head -> insert(head, x, pos);
        cout << endl;
    }
    head -> print(head);
    
    cout << "Delete a number: ";
    cin >> x;
    head -> deleteNode(head, x);
    head -> print(head);

    head -> reverseList(head);
    cout << "Reversed: ";
    head -> print(head);
}