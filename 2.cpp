// Add Two Numbers

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
        ListNode *result = NULL;
        ListNode *p = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int flag = 0;
        while(p1 != NULL && p2 != NULL){
            int val = p1->val + p2->val + flag;
            flag = val / 10;
            val = val % 10;
            ListNode *node = new ListNode(val);
            if(result == NULL) {
                result = node;
                p = node;
            } else {
                p -> next = node;
                p = node;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != NULL){
            int val = p1->val + flag;
            flag = val / 10;
            val = val % 10;
            ListNode *node = new ListNode(val);
            if(result == NULL) {
                result = node;
                p = node;
            } else {
                p -> next = node;
                p = node;
            }
            p1 = p1->next;
        }
        while(p2 != NULL){
            int val = p2->val + flag;
            flag = val / 10;
            val = val % 10;
            ListNode *node = new ListNode(val);
            if(result == NULL) {
                result = node;
                p = node;
            } else {
                p -> next = node;
                p = node;
            }
            p2 = p2->next;
        }
        if(flag!=0){
            ListNode *node = new ListNode(flag);
            if(result == NULL) {
                result = node;
                p = node;
            } else {
                p -> next = node;
                p = node;
            }
        }
        return result;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
