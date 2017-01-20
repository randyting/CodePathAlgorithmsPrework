/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseLinkedList(ListNode* B) {
    ListNode* currNode = B;
    ListNode* prevNode = NULL;
    ListNode* nextNode = B->next;
    while (currNode->next != NULL) {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        nextNode = nextNode->next;
    }
    currNode->next = prevNode;
    return currNode;
}

ListNode* middleNode(ListNode* C) {
    
    int count = 1;
    int middleCount = 0;
    ListNode* currNode = C;
    ListNode* midNode = C;
    while (currNode->next != NULL) {
        count++;
        if (count/2 > middleCount) {
            middleCount = count/2;
            midNode = midNode->next;
        }
        currNode = currNode->next;
    }
    
    if (count%2 == 0 || count == 1) {
         return midNode;   
    } else {
        return midNode->next;
    }
    
}

ListNode* Solution::subtract(ListNode* A) {
    
    if (middleNode(A) == A) {
        return A;
    }
    
    ListNode* revSecondHalf = reverseLinkedList(middleNode(A));
    
    ListNode* nodeFirst = A;
    ListNode* nodeSec = revSecondHalf;
    while ( nodeFirst != NULL && nodeSec != NULL ) {
        nodeFirst->val = nodeSec->val - nodeFirst->val;
        nodeFirst = nodeFirst->next;   
        nodeSec = nodeSec->next;
    }
    
    ListNode *secondHalf = reverseLinkedList(revSecondHalf);
    
    return A;
    
}