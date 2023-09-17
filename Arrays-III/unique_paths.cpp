class Solution {
  public:
 
 int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        //Base case
        if(i<0 || j<0 || i>=m || j>=n)
        {
          return 0;
        }
       
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        //desti
        if(i==m-1 && j==n-1)
        {
            //reached desti.
            return 1;
        }

        //choices
        
        int goright=solve(i,j+1,m,n,dp);
        int godown=solve(i+1,j,m,n,dp);
        dp[i][j]=goright+godown;
        return dp[i][j];
    }
    int nCr(int n,int r)
    {
        if(n==0 || r==0)
        return 1;
        long long ans=1;
        for(int i=0;i<r;i++)
        {
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    int uniquePaths(int m, int n) 
    {
      //This is recurion problem

      //Approch 1 Using recursin
      //TC : O(2^(m+n)) & SC : O(m+n)
      //37/63 passed TLE
      
      //Create safe state
      //Recursive function
      //Recall it and them put backtrekking

      //APproch 2 using dp
      //choices pattern
      //TC O(m*n)

      vector<vector<int>>dp(101,vector<int>(101,-1));
      return solve(0,0,m,n,dp);  

        //Approah 3
        //Using Formula
        //TC : O(n-1) or o(m-1)
        //TLE at 58/63
 
        //Each time we are taking an exactly m+n-2 number of steps to reach the end.
        //Since we need an m+n-2 number of steps to reach the end among those steps 
        //if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations 
        //( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get total paths.
        
        //return nCr(m+n-2,n-1);

    }
};