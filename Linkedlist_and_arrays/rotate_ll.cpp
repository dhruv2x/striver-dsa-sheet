class Solution {
public:
    ListNode* findnewtail(ListNode* head, int ind) {
        int cnt = 1;
        while (head != NULL) {
            if (cnt == ind)
                return head;
            cnt++;
            head = head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        // Brut Force

        // store in deque
        // perfore operations
        // again create new linked list

        // TC :  O(n)
        // code

        // TLE : 12/332

        /*

        if(head==NULL)
        return head;

        deque<int>dq;
        ListNode* copy=head;
        while(copy!=NULL)
        {
            dq.push_back(copy->val);
            copy=copy->next;
        }

        while(k>0)
        {
            int last=dq.back();
            dq.pop_back();
            dq.push_front(last);
            k--;
        }

        //traverse dqque and create ll
        ListNode* newnode=new ListNode(-1);
        ListNode* ans=newnode;
        while(!dq.empty())
        {
            ListNode* tem=new ListNode(dq.front());
            newnode->next=tem;
            newnode=newnode->next;
            dq.pop_front();
        }
        return ans->next;

        */

        // Approach 2

        // Optimization
        // TLE : 12/232

        // if k==size of ll -> it will be same after rotation
        // so our goal is to decrease the count of operations

        /*
        if(len==k)
        return head;

        if(k>len)
        k/=(len+1);
        */

        // Most Optmized Alogo

        // Count lenth f ll and check edge case
        // point tail to head
        // find new tail which is len-k
        // tail next is our new head and store it
        // update tail ->next=NULL

        // code
        if (head == NULL)
            return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        if (k % len == 0) {
            return head;
        } else if (k > len) {
            k = k % len;
        }

        // conect tail with head

        tail->next = head;
        ListNode* newtail = findnewtail(head, len - k);

        ListNode* newhead = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
};