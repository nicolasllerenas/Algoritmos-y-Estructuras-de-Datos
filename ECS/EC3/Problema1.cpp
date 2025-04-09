#include <iostream>
#include <vector>

using namespace std;

// Definición del nodo de la lista enlazada
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // Nodo dummy para simplificar la lógica
        ListNode* current = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }


        current->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

// Función para convertir un vector a una lista enlazada
ListNode* vectorToList(const vector<int>& vec) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int val : vec) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// Función para convertir una lista enlazada a un vector
vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Función principal para probar los casos
int main() {
    Solution sol;

    // Ejemplo 1
    ListNode* list1 = vectorToList({1, 2, 4});
    ListNode* list2 = vectorToList({1, 3, 4});
    ListNode* merged = sol.mergeTwoLists(list1, list2);
    vector<int> result = listToVector(merged);
    cout << "Ejemplo 1: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Ejemplo 2
    ListNode* list3 = vectorToList({});
    ListNode* list4 = vectorToList({});
    merged = sol.mergeTwoLists(list3, list4);
    result = listToVector(merged);
    cout << "Ejemplo 2: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Ejemplo 3
    ListNode* list5 = vectorToList({});
    ListNode* list6 = vectorToList({0});
    merged = sol.mergeTwoLists(list5, list6);
    result = listToVector(merged);
    cout << "Ejemplo 3: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}