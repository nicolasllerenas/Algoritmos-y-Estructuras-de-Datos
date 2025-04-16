#include <iostream>
#include <vector>
using namespace std;

// Definición del nodo para la lista enlazada
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode temp(0);
        temp.next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val >= lastSorted->val) {
                lastSorted = lastSorted->next;
            }
            else {
                ListNode* prev = &temp;
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return temp.next;
    }
};
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}
int main() {
    Solution solution;

    vector<int> values = {4, 2, 1, 3};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    ListNode* sorted = solution.insertionSortList(head);

    cout << "Sorted list:   ";
    printList(sorted);

    return 0;
}
