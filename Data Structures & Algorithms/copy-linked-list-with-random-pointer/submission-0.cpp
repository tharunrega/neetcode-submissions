class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* temp = head;

        while(temp != nullptr){
            Node* front = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = front;
            temp = front;
        }

        temp = head;

        while(temp != nullptr){
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;

            temp = temp->next->next;
        }

        Node* copyHead = head->next;
        temp = head;

        while(temp != nullptr){
            Node* copy = temp->next;
            temp->next = copy->next;

            if(copy->next)
                copy->next = copy->next->next;
            else
                copy->next = nullptr;

            temp = temp->next;
        }

        return copyHead;
    }
};