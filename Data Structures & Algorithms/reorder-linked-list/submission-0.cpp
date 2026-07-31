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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next= prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    void insert(ListNode* head1, ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while(temp1 != nullptr && temp2 != nullptr){
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;
            temp1->next = temp2;
            temp2->next = next1;
            temp1 = next1;
            temp2 = next2;
        }
    }
    ListNode* splitmiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        if(fast->next==nullptr) return head;
        fast = fast->next;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = slow->next;
        slow->next = nullptr;
        return head1;
    }

    void reorderList(ListNode* head) {
        ListNode* j = splitmiddle(head);
        ListNode* i = reverse(j);
        insert(head,i);
    }
};
