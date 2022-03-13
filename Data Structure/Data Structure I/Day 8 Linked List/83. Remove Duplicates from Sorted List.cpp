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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur) {
            ListNode *ptr = cur->next;
            while (ptr && ptr->val == cur->val)
                ptr = ptr->next;
            cur->next = ptr;
            cur = cur->next;
        }
        return head;
    }
};