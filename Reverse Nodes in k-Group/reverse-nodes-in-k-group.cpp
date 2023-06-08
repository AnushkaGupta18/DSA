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
private: 
    int getLength(ListNode* head) {
        ListNode* temp = head; 
        int len = 0; 
        while (temp != NULL) {
            len++; 
            temp = temp -> next; 
        }

        return len;
    }

    ListNode* reverse(ListNode* head, int length, int k) {
        if (length < k || k == 1 || head == NULL || head->next == NULL) {
            return head; 
        }

        ListNode* prev = NULL; 
        ListNode* curr = head; 
        ListNode* forward = NULL;
        int count = 1; 

        while (count <= k && curr!= NULL) {
            forward = curr -> next;
            curr -> next = prev; 
            prev = curr; 
            curr = forward; 
            count++;
        }

        if (forward != NULL) {
            head -> next = reverse(forward, (length - k), k);
        }
        head = prev; 
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head); 

        return reverse(head, len, k);
    }
};