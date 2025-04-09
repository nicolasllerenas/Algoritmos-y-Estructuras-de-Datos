#include <iostream>
using namespace std;

// Definición del nodo para la lista doblemente enlazada
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node *current = head, *tail;
        while (current) {
            if (current->child) {
                tail = current->child;
                while (tail->next) {
                    tail = tail->next;
                }
                tail->next = current->next;
                if (current->next) {
                    current->next->prev = tail;
                }
                current->next = current->child;
                current->next->prev = current;
                current->child = nullptr;
            }
            current = current->next;
        }
        return head;
    }
};

// Función para crear el ejemplo de lista multinivel
Node* createExampleList() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    // Nivel principal: 1 <-> 2 <-> 3 <-> 4
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;

    // Subnivel (hijo de nodo2): 5 <-> 6
    node2->child = node5;
    node5->next = node6;
    node6->prev = node5;

    return node1;
}

// Función para imprimir la lista aplanada
void printFlattenedList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " <-> ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    Solution solution;
    Node* head = createExampleList();

    cout << "Lista original (solo nivel principal): ";
    printFlattenedList(head);  // Imprime 1 <-> 2 <-> 3 <-> 4

    Node* flattenedHead = solution.flatten(head);
    cout << "Lista aplanada: ";
    printFlattenedList(flattenedHead);  // Debe imprimir 1 <-> 2 <-> 5 <-> 6 <-> 3 <-> 4

    // Liberar memoria (opcional)
    Node* current = flattenedHead;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}