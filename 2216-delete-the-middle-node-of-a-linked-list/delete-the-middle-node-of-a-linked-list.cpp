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
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If there's only one node, return nullptr
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* link = nullptr;

        // Find the middle node using the slow and fast pointer technique
        while (fast != nullptr && fast->next != nullptr) {
            link = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Deleting the middle node by skipping over it
        link->next = slow->next;
        
        return head;
    }
};