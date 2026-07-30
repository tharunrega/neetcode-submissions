/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;
        ListNode dummy;
        ListNode* ans = &dummy;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val >= temp2->val){
                ans->next = temp2;
                temp2 = temp2->next;
            }else{
                ans->next = temp1;
                temp1=temp1->next;
            }
            ans = ans->next;            
        }
        while(temp1 != nullptr){
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;
        }        
        while(temp2 != nullptr){
            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }        
        return dummy.next;
    }
};
