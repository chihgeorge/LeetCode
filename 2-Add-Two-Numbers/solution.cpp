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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);                      //  create a dummyhead as the very first node
        ListNode *p = l1, *q = l2, *curr = &dummyHead;  
        int carry = 0;                              //  use to count the carry digit
        
        while( p != NULL || q != NULL){             // go though l1 and l2 
            int x = ( p != NULL) ? p->val : 0;      // if l1 is go over, set the digit as 0
            int y = ( q != NULL) ? q->val : 0;      // same as above
            int digit = x + y + carry;              // add the digit, included the carry
            carry = digit / 10;                     // the new carry is 1 if digit > 10, otherwise is 0          
            curr->next = new ListNode(digit % 10);  // set the next node as the sum of current digits
            curr = curr->next;                      // go to next node
            
            if( p != NULL)  p = p->next;            // if l1 isn't go over, go to next node
            if( q != NULL)  q = q->next;            // same as above
        }
        if(carry > 0)
            curr->next = new ListNode(carry);       // if carry is 1 at the end of the list, that means we need to add a new node 1
        
        return dummyHead.next;
    }
};