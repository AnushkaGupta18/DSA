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
    bool hasCycle(ListNode *head) {
        //Approach one, using a map 
        map <ListNode*, bool> visited; 

        if(head == NULL) {
            return false;
        }

        ListNode* temp = head; 

        while(temp != NULL) {
            //cycle exists
            if(visited[temp] == true) {
                return true;
            }

            visited[temp] = true; 
            temp = temp -> next;
        }

        return false;
        
    }
};