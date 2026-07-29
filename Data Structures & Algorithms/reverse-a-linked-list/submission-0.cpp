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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        unordered_map<ListNode*, ListNode*> mp;

        ListNode* prev = nullptr;
        ListNode* temp = head;
        
        while(temp != nullptr){
            mp[temp] = prev;
            prev = temp;
            temp = temp->next;
        }
        ListNode* end = prev;
        temp = end ;
        while(temp != head){
            temp->next = mp[temp];
            temp = temp->next;
        }
        temp->next = nullptr;
        return end;
        
    }
};
