#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int frontIndex;
    int rearIndex;
    int capacity;
    int *queue;

public:
    Queue(int queueSize) {
        size = 0;
        capacity = queueSize; 
        queue = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
    }

    void enqueue(int value) {
        // Check if the queue is full
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        queue[rearIndex] = value;
        size++;
    }

    void dequeue() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    int front() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1; // or any other suitable default value
        }

        return queue[frontIndex];
    }

    bool isEmpty() {
        return (size == 0);
    }

    int getSize() {
        return size;
    }
};

int main() {
    cout << endl;
    Queue myQueue(3);

    myQueue.enqueue(5);
    myQueue.enqueue(3);
    myQueue.enqueue(7);

    cout << "Front element: " << myQueue.front() << endl;

    myQueue.dequeue();
    cout << "Front element after dequeue: " << myQueue.front() << endl;
    myQueue.dequeue();
    cout << "Front element after dequeue: " << myQueue.front() << endl;
    myQueue.dequeue();
    cout << "Front element after dequeue: " << myQueue.front() << endl;
    myQueue.enqueue(100);
    cout << "Queue size: " << myQueue.getSize() << endl;

    while (!myQueue.isEmpty()) {
        myQueue.dequeue();
    }
    cout << "Queue size after dequeue all: " << myQueue.getSize() << endl;

    return 0;
}
