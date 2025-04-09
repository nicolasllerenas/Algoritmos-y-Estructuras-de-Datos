#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true; // Lista vacía es palíndromo
        if (!head->next) return true;

        ListNode* current = head;
        int size = 0;
        while (current) {
            current = current->next;
            size++;
        }

        current = head;
        for (int i = 0; i < (size/2) - 1; i++) {
            ListNode* second = current->next;
            current->next = second->next;
            second->next = head;
            head = second;
        }

        ListNode* current2 = head;
        current = current->next;
        if (size % 2 != 0) {
            current = current->next;
        }

        while (current) {
            if (current->val != current2->val) return false;
            current = current->next;
            current2 = current2->next;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Caso de prueba 1: [1, 2, 2, 1]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    cout << "Lista 1: ";
    printLinkedList(head1);
    cout << "Es palindromo? " << (solution.isPalindrome(head1) ? "Si" : "No") << endl;

    // Caso de prueba 2: [1, 2]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "\nLista 2: ";
    printLinkedList(head2);
    cout << "Es palindromo? " << (solution.isPalindrome(head2) ? "Si" : "No") << endl;

    // Caso de prueba 3: Lista vacía
    ListNode* head3 = nullptr;
    cout << "\nLista 3: ";
    printLinkedList(head3);
    cout << "Es palindromo? " << (solution.isPalindrome(head3) ? "Si" : "No") << endl;

    return 0;
}