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
    ListNode* solve(ListNode* list1, ListNode* list2) {

        ListNode* curr1 = list1; 
        ListNode* curr2 = list2; 
        ListNode* next1 = list1 -> next; 
        ListNode* next2 = list2 -> next; 

        while(next1 != NULL && curr2 != NULL) {
            if((curr2 -> val >= curr1 -> val) && 
            (curr2 -> val <= next1 -> val)) {
                //adding the new element
                curr1 -> next = curr2; 
                next2 = curr2 -> next; 
                curr2 -> next = next1; 

                curr1 = curr2; 
                curr2 = next2; 
            }
            else {
                curr1 = next1; 
                next1 = next1 -> next;

                if(next1 == NULL) {
                    curr1 -> next = curr2; 
                    return list1;
                }

            }
        }

        return list1; 

    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //empty list 1
        if(list1 == NULL) {
            return list2;
        }
        //empty list 2
        if(list2 == NULL) {
            return list1;
        }
        //list 1 has only one element 
        if((list1 -> next == NULL) && (list1 -> val <= list2 -> val)) {
            list1 -> next = list2; 
            return list1;
        }
        //list 2 has only one element
        if((list2 -> next == NULL) && (list2 -> val <= list1 -> val)) {
            list2 -> next = list1; 
            return list2;
        }

        if(list1 -> val <= list2 -> val) {
            return solve(list1, list2);
        }
        else {
            return solve(list2, list1);
        }
    }
};