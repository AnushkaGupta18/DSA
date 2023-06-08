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
    ListNode* getMiddle(ListNode* head) {
        ListNode* fast = head -> next; 
        ListNode* slow = head; 

        while(fast != NULL && fast ->next != NULL) {
            fast = fast -> next -> next; 
            slow = slow -> next; 
        }

        return slow; 
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        if(first == NULL) {
            return second; 
        }

        if(second == NULL) {
            return first;
        }

        ListNode* ans = new ListNode(-1); 
        ListNode* temp = ans; 

        while(first != NULL && second != NULL) {
            if(first -> val <= second -> val) {
                temp -> next = first;
                first = first -> next;  
            }
            else {
                temp -> next = second; 
                second = second -> next; 
            }

            temp = temp -> next; 
        }

        if(first != NULL) {
            temp -> next = first;
        }

        if(second != NULL) {
           temp -> next = second;  
        }

        ans = ans -> next; 
        return ans; 
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL ) {
            return head;
        }
        
        //finding the middle element 
        ListNode* mid = getMiddle(head); 

        ListNode* left = head; 
        ListNode* right = mid -> next; 
        mid -> next = NULL;

        //recursively sort the left and right parts 
        left = sortList(left); 
        right = sortList(right); 

        //merge the two halves 
        ListNode* ans = merge(left, right); 

        //return ans 
        return ans; 
    }
};