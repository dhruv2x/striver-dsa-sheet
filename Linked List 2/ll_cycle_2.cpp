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
    ListNode *detectCycle(ListNode *head) 
    {

        //Approach 1
        //use visited vector for each node

        unordered_map<ListNode*,ListNode*>mp;
        

        while(head!=NULL)
        {
            if(mp.find(head->next)!=mp.end())
            {
                //next pointer already visited
                return head->next;
            }
            else
            {
                mp[head]=head->next;
            }
            head=head->next;
        }
        ListNode* ans=NULL;
        return ans;
    }
};