class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        //Appoch 1

        //TC : O(n*n) TLE 203/210

        //using Brut Force Approch
        /*
        int cur_sum=0,maxsum=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            int cur_sum=0;
            for(int j=i;j<n;j++)
            {
                cur_sum+=nums[j];
                maxsum=max(maxsum,cur_sum);
            }
        }
        return maxsum;
        */

        //Approch 2
       //Using kadane

         int n,cum_sum=0,fin_sum=0;
        n=nums.size();
        for(int i=0;i<n;i++)
        {
            cum_sum=cum_sum+nums[i];
            if(cum_sum>fin_sum)
            {
                fin_sum=cum_sum;
            }
            if(cum_sum<0)
            {
                cum_sum=0;
            }
        }
        if(fin_sum<=0)
        {
            int d=*max_element(nums.begin(),nums.end());
            return d;
        }
        else
        {
            return fin_sum;
        }
        
    }
};