#include <iostream>
using namespace std;
#include "HeapClass.cpp"

class PriorityQueue { // using circular array
    MinHeap heap;
    
    public:
        bool isEmpty() {
            if (heap.get_lastindex() == 0) return true;
            else return false;
        }

        void enqueue(int data) {
            heap.insert(data);
        }

        int dequeue() {
            if (isEmpty()) cout << "Empty queue!" << endl;
            else return heap.del();
        }

        void print() {
            heap.print();
        }
};

int main() {
    PriorityQueue queue;
    queue.dequeue();
    queue.enqueue(1);
    queue.enqueue(6);
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(2);
    queue.enqueue(4);
    queue.print();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.print();
} 