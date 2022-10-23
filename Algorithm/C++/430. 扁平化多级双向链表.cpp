class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }
        Node *cur = head;
        Node *tail;
        while(cur != nullptr){
            if(cur->child != nullptr){
                tail = cur->child;
                while(tail->next != nullptr){
                    tail = tail->next;
                }
                if(cur->next != nullptr){
                    cur->next->prev = tail;
                    tail->next = cur->next;
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            cur = cur->next;
        }
        return head;
    }
};