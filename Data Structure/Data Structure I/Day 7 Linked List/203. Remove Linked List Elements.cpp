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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(val - 1);
        dummy->next = head;
        ListNode* ans = dummy;

        ListNode* prev = dummy;
        ListNode* prob = head;
        while (prob) {
            while (prob && prob->val == val) {
                prob = prob->next;
            }
            prev->next = prob;
            prev = prob;
            prob = prob ? prob->next : prob;
        }
        return ans->next;
    }
};