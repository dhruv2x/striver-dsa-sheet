vector<int> findTwoElement(vector<int> arr, int n) 
    {
        //Using Map 
        //TC : O(n) 
        //SC : O(n)
        
        /*
        
        unordered_map<int,int>mp;
        
        vector<int>ans(2,0);
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
       for(int i=1;i<=n;i++)
       {
           if(mp[i]>1)      //repeting
           {
               ans[0]=i;
           }
           else if(mp[i]==0)    //missing
           {
               ans[1]=i;
           }
       }
       
        return ans;
        
        */
        
        //Without using extra space
        //TC : O(n)
        //We use math equations
        
        /*
        Misisng number=Y and Repeated number is X 
        
        Sum of n numbers is Sn=n*(n+1)/2
        Sum of given array is Sg
        Sn-Sg=X-Y                 ----> Eq 1
        
        Sum of square of n numbers is Sq=n*(n+2)(2*n+1)/6 -> 5
        Sum of square of given array Sqg  -> 8
        Sqg-Sq=X*X - Y*Y                ----> Eq 2
        
        As we know x2+y2=(x+y)(x-y)
        So Sqg-Sq=(X-Y)(X+Y)
        Put value of X-Y 
        Sqg=Sq=(Sn-Sg)*(X+Y)            ----> Eq 3
        
        Find X and Y using Eq 1 an 3
        
        */
        
        //Sn -> sum of n
        //Sg -> sum of given
        //Sq -> sequare of n
        //Sqn -> square of given
       
        long long Sn = (n * (n + 1)) / 2;
        long long Sq = (n * (n + 1) * (2 * n + 1)) / 6;

        long long Sg = 0, Sqg = 0;
        for (int i = 0; i < n; i++) 
        {
            Sg += arr[i];
            Sqg += (long long)arr[i] * (long long)arr[i];
        }
        
        //Eq 1 X-Y =Sn-Sg               -> val1
        //Eq 3 X+Y =(Sqg-Sq)/(Sn-Sg)    -> val2
        
        //So X=sum/2 fo val1 and val2
        //Y=val1-X
        
        //Goven sum will always greate then n number sum
        
        int val1=Sg-Sn;
        int val2=(Sqg-Sq)/val1;
        
        int x=(val1+val2)/2;
        int y=val2-x;
        
        vector<int>ans(2,0);
        ans[0]=x;
        ans[1]=y;
        return ans;
    }