/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int getDifference(ListNode* headA,ListNode* headB) {
     int len1 = 0,len2 = 0;
        while(headA != NULL || headB != NULL) 
        {
            if(headA != NULL) 
            {
                ++len1; headA = headA->next;
            }
            if(headB != NULL) 
            {
                ++len2; headB = headB->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        /*
        ListNode* d1 = headA;
        ListNode* d2 = headB;
    
    while(d1 != d2) {
        if(d1==NULL)
        {
            d1=headB;
        }
        else
        {
            d1=d1->next;
        }
        if(d2==NULL)
        {
            d2=headA;
        }
        else
        {
            d2=d2->next;
        }
    }
    
    return d1;
    */

    //Approach 2

    /*
O(2*max len of both LL))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))

Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.
    */

     int diff = getDifference(headA,headB);

        if(diff < 0) 
            while(diff++ != 0) 
            headB = headB->next; 
        else 
            while(diff-- != 0) 
            headA = headA->next;
        
        while(headA != NULL) 
        {
            if(headA == headB) 
            return headA;
            
            headB = headB->next;
            headA = headA->next;
        }
        return headA;


        
    }
};