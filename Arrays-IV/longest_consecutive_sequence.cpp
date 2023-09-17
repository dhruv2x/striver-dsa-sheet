class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        //corner case
        if(nums.size()==0 || nums.size()==1)
        {
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        //Approch
        
        //Use kadane
        int curdiff=1,maxdiff=INT_MIN;
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i+1]-nums[i]==1))
            {
                curdiff++;
            }
            else if(nums[i+1]==nums[i])
            {
                continue;      
                //This is tricky as for same sequence 
                //we dont have to do anything
            }
            else
            {
                curdiff=1;
            }
            if(curdiff>maxdiff)
            {
                maxdiff=curdiff;
            }
        }
        if(maxdiff==INT_MIN)
        {
            return 1;
        }
        else
        {   
             return maxdiff; 
        }       
    }
};