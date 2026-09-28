struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* temp = head;
    int count = 0;

    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k)
        return head;

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    for (int i = 0; i < k; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = reverseKGroup(curr, k);

    return prev;
}