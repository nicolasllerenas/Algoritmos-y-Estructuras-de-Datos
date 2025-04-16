#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack myStack;


    myStack.push(1);
    myStack.push(2);
    
    cout << "top() -> " << myStack.top() << endl;    // Debe imprimir 2
    cout << "pop() -> " << myStack.pop() << endl;    // Debe imprimir 2
    cout << "empty() -> " << (myStack.empty() ? "true" : "false") << endl; // Debe imprimir false

    return 0;
}