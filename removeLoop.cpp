 void removeLoop(Node* head) {
        // code here
        Node* slow = head; 
        Node* fast = head;
        
        while(slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if( slow != fast || slow == NULL || fast == NULL) 
            return;
    
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        Node* p = slow->next;
        while(p->next != slow)
            p = p->next;
        p->next = NULL;
    }
