 ListNode* reverseList(ListNode* head) 
    {
        //Approch 1
        
        //Iterative way
        /*
        if(head==NULL)
        {
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextptr=head->next;
        
        while(curr!=NULL)
        {
            //We assign curr next to prevptr
            curr->next=prev;
            
            //move all forword
            
            prev=curr;
            curr=nextptr;
            if(nextptr!=NULL)
            nextptr=nextptr->next;
        }
        return prev;
        */

        //APproch 2

        //Using recursion
        //What we do is
        //We tell recurion to reverse from (head-> next) to tail
        //after recurion it returns new head which is tail
        //Now it will be like
        //1 -> 2 <- 3 <- 4 <-5 
        //and we have to make 1->next=Null and 2->next=1
        //and head is 1
        //head->next=2
        //so head->next->next=head
        //and head->next=NULL

        //Base case
        if(head==NULL || head->next==NULL)
        {
           return head;
        }
        
        ListNode* newhead=reverseList(head->next); //Recursive call
        
        head->next->next=head;  //Its like Cur points next
        head->next=NULL;    
     //as this head will become tail after revesing
        return newhead;  
    }