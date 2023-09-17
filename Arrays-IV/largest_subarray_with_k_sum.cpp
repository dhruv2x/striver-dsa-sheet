 int maxLen(vector<int>&A, int n)
    {   
        //Obsservations
        
        //goal : find subarray with sum=0
        
        //APproch 1 Using 2 For loop
        //TC : O(n*n)
        //Claculate if sum==0 return j-i+1
        //But here we have to find the max subarray
        
        //Code
        /*
        int maxsub=0;
        for(int i=0;i<n;i++)
        {
            int cursum=0;
            for(int j=i;j<n;j++)
            {
                cursum+=A[j];
                if(cursum==0)
                {
                    maxsub=max(maxsub,(j-i+1));
                }
            }
        }
      
        return maxsub;
        */
        
        //Approach 2
        
        //using pre-fix sum
        //{15,-2,2,-8,1,7,10,23}
        //15  13 15
        //Here at 2nd index again 15 came
        //and we already have 15 at index 0 consider as x
        //which means x+1 to ith is 0
        
        unordered_map<int,int>mp;
        int maxLen=0;
        int cursum=0;
        for(int i=0;i<n;i++)
        {
            cursum+=A[i];
            if(cursum==0)
            {
                maxLen=i+1; //as length will be i+1
            }
            if(mp.find(cursum)!=mp.end())
            {
                //if cursum already present in set
                int ind=mp[cursum];
                maxLen=max(maxLen,i-ind);     //distance between ind and i
            }
            else
            {
                mp[cursum]=i;
            }
        }
        return maxLen;
        
    }