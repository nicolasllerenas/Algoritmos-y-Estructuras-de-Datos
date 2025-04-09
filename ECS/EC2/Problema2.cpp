class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        int size = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            size++;
        }
        tail->next = head;

        k = k % size;
        int toNewHead = size - k;
        ListNode* newTail = head;
        for (int i = 1; i < toNewHead; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};