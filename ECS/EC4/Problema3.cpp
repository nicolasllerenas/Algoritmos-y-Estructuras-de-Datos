#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        
        arr[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        
        arr[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        
        size--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }
};

int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);
    cout << boolalpha; 
    
    cout << obj->insertLast(1) << endl;   // true
    cout << obj->insertLast(2) << endl;   // true
    cout << obj->insertFront(3) << endl;  // true
    cout << obj->insertFront(4) << endl;  // false (lleno)
    cout << obj->getRear() << endl;       // 2
    cout << obj->isFull() << endl;        // true
    cout << obj->deleteLast() << endl;    // true
    cout << obj->insertFront(4) << endl;  // true
    cout << obj->getFront() << endl;      // 4
    
    delete obj;
    return 0;
}