class Solution {
public:
    void setzero(vector<vector<int>>&matrix,int n,int m,int i,int j,int newval)
    {
        //set all elements of i to newval
        for(int k=0;k<m;k++)
        {
            if(matrix[i][k]!=0)
            matrix[i][k]=newval;
        }
        //set all elements of j to newval
        for(int k=0;k<n;k++)
        {
            if(matrix[k][j]!=0)
            matrix[k][j]=newval;
        }
    } 
    void setZeroes(vector<vector<int>>& matrix) 
    {
        //simple traversal
        //First traverse and dound 0 then set -1 in entire row and col excel 0
        //Then agai traverse and if found -1 then set to 0
        
        //TC : 2*O(N*M) +o(N*M)

        int n=matrix.size();
        int m=matrix[0].size();
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    setzero(matrix,n,m,i,j,-1);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==-1)
                {
                    matrix[i][j]=0;       
                }
            }
        }        
    }
};