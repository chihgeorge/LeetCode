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
        ListNode dummyHead(0);                          //  create a dummyhead as the very first node
        dummyHead.next = head;                          
        ListNode *p = head, *prev = &dummyHead; 
        
        while( p != NULL && p->next != NULL){           //  go though all node in list except the last one
            ListNode *q = p->next, *r = p->next->next;  //  prev -> p -> q -> r  -->  prev -> q -> p -> r
            prev->next = q;
            q->next = p;
            p->next = r;
            prev = p;                                   //  the new prev is the p after swap, so that r and r->next will swap in next round
            p = r;                                      //  the new p is r
        }
        
        return dummyHead.next;
    }
};