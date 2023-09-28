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
ListNode* reverse(ListNode* head)
{
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nxt=head->next;

    while(curr!=NULL)
    {
        curr->next=prev;
        //move all 3
        prev=curr;
        curr=nxt;
        if(nxt!=NULL)
        nxt=nxt->next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) 
    {
        /*
        //Approch 1 using stack

        stack<int>st;
      
      //As stack contains property that whatever will store in stack 
      //we can get the last element easily
      //So will take that last element and compare with first element of our linked list
      ListNode* temp=head;
      while(temp!=NULL)
      {
        st.push(temp->val);
        temp=temp->next;
      }
      temp=head;    //Tricky
      while(temp!=NULL)
      {
        if(temp->val!=st.top())
        {
          return false;
          break;
        }
        st.pop();
        temp=temp->next;
      }
    
      
      return true;
      */

      //Approch 2 using fast and slow pointers

      //TC : 3*O(n/2)
      //For all 3 steps

      //3 steps

      //1 find middle and put slow on middle
      //2 reverse right half
      //2 compare slow with begining usin dummy node step by step
      
        ListNode* dummy=head;
        ListNode* slow=head;
        ListNode* fast=head;

        //edge case
        if(head==NULL || head->next==NULL)
        {
          return true;
        }
        //1

        //fast 2 step and slow 1 step

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        //now slow is middle node

        //2 reverse right half
        
        slow->next=reverse(slow->next);
      slow=slow->next;  //as we have to compare with right half
        //3
        //compare with dummy

        while(slow!=NULL)
        {
            if(slow->val!=dummy->val)
            {
                return false;
            }
            slow=slow->next;
            dummy=dummy->next;
        } 
        return true;
        
    }
};