#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int MAX_SIZE = 30000;

class MinStack {
private:
    int* stack;
    int* minStack;
    int topIndex;
    int minTopIndex;

public:
    MinStack() {
        stack = new int[MAX_SIZE];
        minStack = new int[MAX_SIZE];
        topIndex = -1;
        minTopIndex = -1;
    }

    void push(int val) {
        stack[++topIndex] = val;
        if (minTopIndex == -1 || val <= minStack[minTopIndex]) {
            minStack[++minTopIndex] = val;
        }
    }

    void pop() {
        if (topIndex == -1) return;
        if (stack[topIndex] == minStack[minTopIndex]) {
            minTopIndex--;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) return INT_MIN;
        return stack[topIndex];
    }

    int getMin() {
        if (minTopIndex == -1) return INT_MIN;
        return minStack[minTopIndex];
    }
};

int main() {
    vector<string> operations = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> values = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};

    vector<string> output;
    MinStack* minStack = nullptr;

    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == "MinStack") {
            minStack = new MinStack();
            output.push_back("null");
        } else if (operations[i] == "push") {
            minStack->push(values[i][0]);
            output.push_back("null");
        } else if (operations[i] == "pop") {
            minStack->pop();
            output.push_back("null");
        } else if (operations[i] == "top") {
            output.push_back(to_string(minStack->top()));
        } else if (operations[i] == "getMin") {
            output.push_back(to_string(minStack->getMin()));
        }
    }

    // Imprimir salida como lista JSON
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i != output.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}