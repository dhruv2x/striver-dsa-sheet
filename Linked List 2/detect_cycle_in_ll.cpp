bool hasCycle(ListNode *head) 
    {
        ListNode* slow=head;    //1 move
        ListNode* fast=head;    //2 move
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return false;
        }
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            //if it contains cycle at any given point both slow and fast
            //will colide
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }