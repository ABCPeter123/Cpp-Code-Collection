#include <iostream>
using namespace std;
#define SIZE 10

class Queue { // using circular array
    int queue[SIZE];
    int front;
    int rear;
    public:
        Queue() {
            front = -1;
            rear = -1;
        }
        
        bool isEmpty() {
            if ((front == -1) && (rear == -1)) return true;
            else return false;
        }

        int getFront() {
            return queue[front % SIZE];
        }

        int getRear() {
            return queue[rear % SIZE];
        }

        void enqueue(int data) {
            if((rear + 1) % SIZE == front) { // circular array
                cout << "Queue is full!" << endl;
                return;
            }
            else if ((front == -1) && (rear == -1)) {
                front = 0;
                rear = 0;
            }
            else rear = (rear + 1) % SIZE; // circular array with module
            queue[rear] = data;
        }

        void dequeue() {
            if ((front == -1) && (rear == -1)) {
                cout << "Queue is empty!" << endl;
                return;
            }
            else if (front == rear) {
                front = -1;
                rear = -1;
            }
            else front = (front + 1) % SIZE;
        }

        void print() {
            int rear_temp = rear;
            if (rear < front) {
                rear_temp += SIZE;
            }
            cout << "Queue: ";
            for (int i = front; i <= rear_temp; i++) {
                cout << queue[(i % SIZE)] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue queue;
    queue.dequeue();
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.enqueue(11);
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.enqueue(11);
    queue.enqueue(12);
    queue.print();
    queue.enqueue(13);
}