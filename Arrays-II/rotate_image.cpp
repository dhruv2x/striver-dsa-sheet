class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
       //Observations

       //0th row converts -> nth colum
       //n-1 th row converts -> 0th colum

    //    matrix[0][0] -> matrix[0][n-1]
    //    matrix[0][1] -> matrix[1][n-1]
    //    matrix[0][2] -> matrix[2][n-1]

        //Approach 1 Brut Force
        //Create new newmat and store as asked
        //O(N*N) : Accepted
        /*

        int n=matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=matrix[n-j-1][i];
            }
        }
        matrix=ans;
        
        */

        //Opyimal for space TC : O(N*N) + O(N*N) and SC : O(1)

        //By observation, 
        //we see that the first column of the original matrix 
        //is the reverse of the first row of the rotated matrix, 

        //So transpose and reverse each row

        int n=matrix.size();
     
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)    //Note that j<i
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};