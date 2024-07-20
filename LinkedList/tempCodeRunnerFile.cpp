ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!= NULL)
        {
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;