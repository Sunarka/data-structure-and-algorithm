#include <iostream>
using namespace std;

class Queue {
public:
    int size = 0;
    int front = 0;
    int rear = -1;
    char *items;

    Queue(int queueSize) { // constructor
        size = queueSize;
        items = new char[size];
    }

    void enqueue(char item) {
        if (rear == size - 1) {
            cout << "Queue Overflow, queue is full" << endl;
        } else {
            rear++;
            items[rear] = item;
        }
    }

    char dequeue() {
        char item = '\0'; // Initialize with null character
        if (front > rear) {
            cout << "Queue is empty" << endl;
        } else {
            item = items[front];
            front++;
        }
        return item; // Return the dequeued item
    }
};

int main() {

    Queue kantong1(5); // misalkan

    kantong1.enqueue('A');
    kantong1.enqueue('B');
    kantong1.enqueue('C');
    kantong1.enqueue('Z');
    kantong1.enqueue('Y');

    cout << kantong1.dequeue() << endl;
    cout << kantong1.dequeue() << endl;
    cout << kantong1.dequeue() << endl;
    cout << kantong1.dequeue() << endl;
}
