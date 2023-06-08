/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private: 
    void insertAtTail(Node* &head, Node* &tail, int data) {
        Node* temp = new Node(data);
        
        if(head == NULL) {
            head = temp; 
            tail = temp; 
        }
        
        else {
            tail -> next = temp; 
            tail = temp; 
        }
        
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL; 
        Node* cloneTail = NULL; 
        
        Node* temp = head; 
        
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp -> val); 
            temp = temp -> next; 
        }
        
        map <Node*, Node*> oldToNew; 
        
        Node* temp1 = head; 
        Node* temp2 = cloneHead;
        
        while(temp1 != NULL || temp2 != NULL) {
            oldToNew[temp1] = temp2; 
            temp1 = temp1 -> next; 
            temp2 = temp2 -> next; 
        }
        
        temp2 = cloneHead; 
        temp1 = head;
        
        while(temp2 != NULL) {
            temp2 -> random = oldToNew[temp1 -> random]; 
            temp1 = temp1 -> next; 
            temp2 = temp2 -> next; 
        }
        
        return cloneHead; 
    }
};