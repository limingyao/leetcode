// Delete Node in a Linked List

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
    void deleteNode(ListNode* node) {
        if(node==NULL||node->next==NULL) {
            return;
        }
        ListNode* p = node -> next;
        node -> val = p -> val;
        node -> next = p -> next;
        delete p;
    }
};


// Method 2:
void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}
