class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Approach 1 take curr and find how many curr are there in future
        //TC O(n*n) using 2 for loops

        //Approach 2 We may use cunt STL instead loop but TC will be same

        //Approach 3 use hashmap 
        //TC O(n*log(n) + O(n)) -> insertion in map and traverse

        //Approach 4
        //TC :o(n)+O(n)

        //moose's voting algo
        //keep track of the occurrences of the majority element 
        //and minority elements dynamically. 
        //start from 0 and cnt=0
        //if found element equals to first element cnt++
        //else cnt--
        //if cnt becomes 0 that means start index is no major element
        //If element appears more then (n/2) times cnt can't be 0
        //make now find for element on cnt=0 index

        //code
        int cnt=0,el=nums[0],n=nums.size();
        for(int i=0;i<n;i++)
        {
                if(cnt==0)
                {
                    cnt=1;  //guess ith element as majority element
                    el=nums[i];
                }
                else if(el==nums[i])
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
        }


        //Now we have to check stored el is majority or not
        int majority_cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el)
            {
                majority_cnt++;
            }
        }
        if(majority_cnt>n/2)    //More than (n/2)
        {
            return el;
        }
        else
        {
            return -1;
        }


    }
};