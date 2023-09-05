class Solution {
public:
    int nCr(int n,int r)
    {
        if(n==0 || r==0)
        {
            return 1;
        }
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<int>generaterow(int row)
    {
        vector<int>temp;
        //we know that starting 1 is fixed
        temp.push_back(1);
        int ans=1;
        for(int col=1;col<row;col++)
        {
            ans=ans*(row-col);
            ans=ans/col;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) 
    {
        
        //Approach 1 Using formula (r-1)C(c-1)
        //Accepted
        //TC : O(N*N)

        /*
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            vector<int>temp;
            for(int j=1;j<=i;j++)
            {
                temp.push_back(nCr(i-1,j-1));
            }
            ans.push_back(temp);
        }
        return ans;
        */

        //Approach 2 Using optimization of formula
        //Instead calculating for all numbers we can you prev numbers
        //TC :O(N)

        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            //This is row
            vector<int>temp=generaterow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};