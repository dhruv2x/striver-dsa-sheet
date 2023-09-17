ListNode* middleNode(ListNode* head) {
        //approch
        
        //count total nodes
        //than count middle node
        //than travverse and return middle jode
        
        //code
        /*
        ListNode* temp=head;
        int sz=0;
        while(temp!=NULL)
        {
            temp=temp->next;
           sz++;
        }
        int mid;
            mid=sz/2+1;
        int cnt=0;
        while(head!=NULL)
        {  
            cnt++;
            if(cnt==mid)
            {
                break;
            } 
        else
           head=head->next;
           
        }
        return head;
        */

        //Approch 2 

        //Use slow and fast pinters

        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL)
        {
            ListNode* temp=NULL;
            return temp;
        }
       while(slow!=NULL && fast!=NULL && fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
       }

       return slow;
}