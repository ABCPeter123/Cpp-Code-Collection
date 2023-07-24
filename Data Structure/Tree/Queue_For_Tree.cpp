#include <iostream>
using namespace std;
#define SIZE 100

struct Queue { // using circular array
    int queue[SIZE];
    int front;
    int rear;
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