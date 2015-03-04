// Linked List Cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* fast = head;
        if(head->next==NULL){
            return false;
        }
        ListNode* slow = head->next;
        while(slow->next!=NULL&&slow->next->next!=NULL){
            if(fast==slow){
                return true;
            }
            fast = fast->next;
            slow = slow->next->next;
        }
        return false;
    }
};
