/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode *p = head, *prev = &dummyHead;
        
        while( p != NULL && p->next != NULL){
            ListNode *q = p->next, *r = p->next->next;
            prev->next = q;
            q->next = p;
            p->next = r;
            prep = p;
            p = r;
        }
        
        return dummyHead.next;
    }
};