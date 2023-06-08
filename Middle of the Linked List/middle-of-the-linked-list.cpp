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
        int len = 0; 

        while(head != NULL) {
            len++; 
            head = head -> next; 
        }

        return len; 
    }

public:
    ListNode* middleNode(ListNode* head) {
        
        int ans = 0; 
        int len = getLength(head); 

        ans = len/2; 

        int count = 0; 
        ListNode* temp = head;
        while(count < ans) {
            temp = temp -> next; 
            count++;
        }

        return temp;

    }
};