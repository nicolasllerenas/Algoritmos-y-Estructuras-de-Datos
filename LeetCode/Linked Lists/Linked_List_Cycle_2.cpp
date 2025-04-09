#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode *slow = head, *fast = head;
        bool hasCycle = false;

        // Detectamos el ciclo
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return nullptr;

        // Encontrar inicio del ciclo
        ListNode *slow2 = head;
        while (slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }

        return slow;
    }
};

int main() {
    // Ejemplo 1: Ciclo en índice 1
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node_4 = new ListNode(-4);
    node3->next = node2;
    node2->next = node0;
    node0->next = node_4;
    node_4->next = node2;  // Ciclo en nodo 2 (índice 1)

    Solution sol;
    ListNode* result = sol.detectCycle(node3);

    if (result) {
        ListNode* temp = node3;
        int index = 0;
        while (temp != result) {
            temp = temp->next;
            index++;
        }
        cout << "Ejemplo 1: tail connects to node index " << index << endl;
    } else {
        cout << "Ejemplo 1: no cycle" << endl;
    }

    // Ejemplo 2: Ciclo en índice 0
    ListNode* node1 = new ListNode(1);
    ListNode* node2_2 = new ListNode(2);
    node1->next = node2_2;
    node2_2->next = node1;  // Ciclo en nodo 1 (índice 0)

    result = sol.detectCycle(node1);
    if (result) {
        ListNode* temp = node1;
        int index = 0;
        while (temp != result) {
            temp = temp->next;
            index++;
        }
        cout << "Ejemplo 2: tail connects to node index " << index << endl;
    } else {
        cout << "Ejemplo 2: no cycle" << endl;
    }

    // Ejemplo 3: Sin ciclo
    ListNode* node1_solo = new ListNode(1);
    result = sol.detectCycle(node1_solo);
    cout << "Ejemplo 3: " << (result ? "tail connects" : "no cycle") << endl;

    // Liberar memoria (omitido por simplicidad en listas con ciclos)
    return 0;
}