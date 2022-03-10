struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto getLength = [&](ListNode *node) {
        int length = 0;
        while (node != NULL) {
            length += 1;
            node = node->next;
        }
        return length;
    };

    int lenA = getLength(headA), lenB = getLength(headB);
    if (lenA > lenB) {
        swap(headA, headB);
        swap(lenA, lenB);
    }
    int diff = lenB - lenA;
    ListNode *nodeA = headA, *nodeB = headB;

    while (diff--) { // After performing nodeB = nodeB->next, diff -= 1
        nodeB = nodeB->next;
    }

    while (nodeA != nodeB) {
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return nodeA;
}
