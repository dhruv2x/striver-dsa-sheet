void deleteNode(ListNode* node) 
    { 
        //Trick is just to update node with current next
        //ex : [4,5,1,9] and node=1
        //simpley -> update 1 is node 
        //simpley change node to 9 and move next pointer to
        //next of 9
        
      ListNode* nxt=node->next;
      
      node->val=nxt->val;       //Vale is updated
      node->next=nxt->next; //next pointer also updated
      
      delete nxt;  
    }