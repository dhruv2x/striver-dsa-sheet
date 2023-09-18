 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    { 
        //Approch
      
      //We will create new Node and add sum+carry
      //Also create one dummy node for carry
      
      ListNode* dummy=new ListNode(0);

      
      //This dummy node helps us to joint and create new nodes
      ListNode* ans=dummy;    //Now our ans list have 1 node as dummy
            
      int carry=0;
      while(l1!=NULL || l2!=NULL || carry==1)
      {
        //Here carry==1 is tricky as carry may left at the end
        int sum=0;
        if(l1!=NULL)
        {
          sum=sum+l1->val;
          l1=l1->next;
        }
        if(l2!=NULL)
        {
          sum=sum+l2->val;
          l2=l2->next;
        }
       
        //Now it may possible that after adding carry
        //sum becmes more than 10
        //So that first add carry than modify carry for future
        
        sum=sum+carry;   
        carry=sum/10;   //ex sum=12 than carry is 1
        
        ListNode* temp=new ListNode();
        temp->val=sum%10;   //ex sum=12 than only add 0
        ans->next=temp;   //Just add this temp node in our ans    
        ans=ans->next; 
      }    
        return dummy->next;   
    }