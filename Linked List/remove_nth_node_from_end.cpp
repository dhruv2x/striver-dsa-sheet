/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        /*
      //First lets measure length of the linked list
      
      ListNode* temp=head;
      int sz=0;
      while(temp!=NULL)
      {
        sz++;
        temp=temp->next; 
      }
      
      //Now length is sz
      //1st Base condition
      if(sz==1)
      {
        return head->next;
      }
      //2nd if size is equal to n than we have to remove head
      if(sz==n)
      {
        temp=head;
        head=head->next;
        delete temp;
        return head;
      }
      int cnt=1;
      ListNode* temp2=head;
      while(temp2!=NULL)
      {
        if(sz-n==cnt)
        {
           ListNode* TobeDeleted=temp2->next;
           temp2->next=temp2->next->next;
           delete TobeDeleted;
           break;
        }
        temp2=temp2->next;
        cnt++;
      }
      
      return head;
      
      */

        //Approch 2 using slow and fast pointer

        //take dummy node which next points to head
        //Mve fast by n steps
        //after then simply move both by 1
        //when fast==null delete slow


        ListNode* dummy=new ListNode(-1);
        
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;

        return dummy->next; //becuse this is our new head
        
    }
};