 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
      
  //Recursive way
      ListNode* ans;
      
      //In the case if 1 list reached to end and 
      //1 is still left to insert in merges list
      if(list1==NULL)
      {
        return list2;
      }
      if(list2==NULL)
      {
        return list1;
      }
  
      //Now compare values
        if(list1->val<=list2->val)
        {
          ans=list1;  //Directly assign smaller values
          ans->next=mergeTwoLists(list1->next,list2);
          //and for next value put recursive call
        }       
        else 
        {
          ans=list2;
          ans->next=mergeTwoLists(list1,list2->next);
          
        }
        
        
      
      return ans;
      
      
      
      
  /*Iterative way
      
      //Hints
      
      //Create base conditions
      //Use 2 pointer 'l1' 'l2' for 2 list traversal and 
      //create new node 'ans' and pointer 'l3' for merged list
      //point smaller node in next of 'l3->next=l1' and increase pointers
      //Now insert pending elemnts of list if one of list reached to end 
      
      //Base conditions 
      
      if(list1==NULL && list2==NULL)
      {
        return {};
      }
      else if(list1==NULL && list2!=NULL)
      {
        return list2;
      }
      else if(list1!=NULL && list2==NULL)
      {
        return list1;
      }
      else
      {
     
        
      ListNode* ans=new ListNode(); //Wil store sorted & merged list
      ans->val=-1;  //Dummy node
      
      ListNode* l1=list1;   //used to travesal in list1
      ListNode* l2=list2;   //used to travesal in list2
      ListNode* l3=ans;    //used for traversal in ans
       
      
      while(l1!=NULL && l2!=NULL)
      {
        if(l1->val==l2->val)
        {
          //No need of creation of new node and insertion
          //Just point l3 to smaller noded
          l3->next=l1;    
          l1=l1->next;
          l3=l3->next;
          
          l3->next=l2;
          l2=l2->next;
          l3=l3->next;
        }
        else if((l1->val)<(l2->val))
        {
          l3->next=l1;
          l1=l1->next;
          l3=l3->next;
        }
        else
        {
          l3->next=l2;
          l2=l2->next;
          l3=l3->next;
        }    
      }
        
        //Now what if any one linked list is reached to end 
        //and another is still left
        
        //So we have to make insert rest of elements in l3 in case
        //of any one linked list reached to end early
        
        //Some elemet still left in l1
        while(l1!=NULL)
        {
          l3->next=l1;
          l1=l1->next;
          l3=l3->next;
        }
        //Some elemet still left in l2
         while(l2!=NULL)
        {
          l3->next=l2;
          l2=l2->next;
          l3=l3->next;
        }
        return ans->next;   //As we first inserted -1 as dummy node
      }
      
      
 */       
    }