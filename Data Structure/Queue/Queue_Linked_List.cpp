#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

    public:
        void enqueue(Node* &front, Node* &rear, int data) {
            Node* temp = new Node();
            temp -> data = data;
            temp -> next = NULL;
            if (front == NULL && rear == NULL) {
                front = rear = temp;
                return;
            }
            rear -> next = temp;
            rear = temp;
        }

        void enqueue(Node* &front, Node* &rear, int data) {
            Node* temp = new Node();
            temp -> data = data;
            temp -> next = NULL;
            if (front == NULL && rear == NULL) {
                front = rear = temp;
                return;
            }
            rear -> next = temp;
            rear = temp;
        }

        void dequeue(Node* &front, Node* &rear) {
            Node* temp = front;
            if (front == NULL) {cout << "Empty queue!" << endl; return;}
            if (front == rear) front = rear = NULL;
            else front = front -> next;
            delete temp; // free the memory address
        }

        void print(Node* front, Node* rear) {
            Node* temp = front;
            if (temp == NULL) {cout << "Empty queue!" << endl; return;}
            cout << "Queue: ";
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
};

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    front -> dequeue(front, rear);
    front -> enqueue(front, rear, 1);
    front -> enqueue(front, rear, 2);
    front -> enqueue(front, rear, 3);
    front -> enqueue(front, rear, 4);
    front -> enqueue(front, rear, 5);
    front -> print(front, rear);
    front -> dequeue(front, rear);
    front -> print(front, rear);
    front -> dequeue(front, rear);
    front -> dequeue(front, rear);
    front -> dequeue(front, rear);
    front -> dequeue(front, rear);
    front -> print(front, rear);
}