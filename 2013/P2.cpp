#include <iostream>
using namespace std;
#define SIZE 4

class Queue { // using circular array
    int queue[SIZE];
    int front;
    int rear;
    int value = 0;

    public:
        int get_value() {
            return value;
        }
        
        Queue() {
            front = -1;
            rear = -1;
        }

        void enqueue(int data) {
            if((rear + 1) % SIZE == front) { // circular array
                value -= dequeue();
                rear = (rear + 1) % SIZE;
            }
            else if ((front == -1) && (rear == -1)) {
                front = 0;
                rear = 0;
            }
            else rear = (rear + 1) % SIZE; // circular array with module
            queue[rear] = data;
            value += data;
        }

        int dequeue() {
            int save = 0;
            if ((front == -1) && (rear == -1)) {
                return 0;
            }
            else if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {save = queue[front]; front = (front + 1) % SIZE;}
            return save;
        }
};

int main() {
    Queue queue;
    int max = 0;
    cin >> max;
    int n = 0;
    cin >> n;
    int data;
    int counter = 0;
    while (queue.get_value() <= max) {
        cin >> data;
        queue.enqueue(data);
        counter++;
        if (counter == n && queue.get_value() <= max) {cout << counter << endl; return 0;}
    }
    for (int i = 1; i <= n - counter; i++) {
        cin >> data;
    }
    cout << --counter << endl;
}