class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {    
      //Hint
      //Only 3 steps

      //1 -> length<k -> return head
      //2 -> reverse k nodes
      //3 -> attach curr->next=recurion

      if(head==NULL)  //1st Base case
      {
        return {};
      }

      //step 1
      ListNode* temp=head;
     
      int sz=0;
      while(temp!=NULL)
      {
          sz++;
          temp=temp->next;
      }
      if(sz<k)
      {
          return head;
      }
        //Step 2 reverse first k nodes
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* nextptr=NULL;
        int cnt=0;
        while(cur!=NULL && cnt<k)
       {
            nextptr=cur->next;    //Declare nextptr
            cur->next=prev;     //Main approch
    
            ////Increase both pointer
            prev=cur;   
            cur=nextptr; 

            cnt++;    
       }

       //step 3 leave next to recursion
        head->next=reverseKGroup(cur,k);  
        return prev; //This is tricky
    }
};