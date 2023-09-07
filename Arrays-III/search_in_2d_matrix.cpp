class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //Approch 1 Using Brut Force O(n*m)

        // for(auto row : matrix)
        // {
        //     for(auto cell : row)
        //     {
        //         if(cell == target)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        //Approch 2 Using two pointers O(n*log(m))

        //Here each row and col is sorted 
        //so just use two pointers
        //if current is greater than target 
        //than go backwords in same row
        //else go down side in same col

        //code
    
    /*
      int row=matrix.size();
      int col=matrix[0].size();
      
      int i=0;
      int j=col-1;
      
      while(i<row && j>=0)
      {       
        if(matrix[i][j]==target)
        {
          return true;
        }
        else if(matrix[i][j]>target)
        {
          j--;
        }
        else
        {
          i++;
        }
      }
      return false;   

      */

        //Approach 3 Better O(n+Log(m))

        /*
        for (int i = 0; i < n; i++) 
        {
            if (matrix[i][0] <= target && target <= matrix[i][m - 1]) 
            {
                return binarySearch(matrix[i], target);
            }
        }
        return false;
        */
    
        //Approach 4 Optimal in O(log(m*n))

        //Flttern 2D matrix then array size will be 0 to n*m-1
        //and apply BS
        //Now I have mid but how can i find coordinates in 2D matrix
        //row=mid/m
        //col=mid%m
        
      int n=matrix.size();
      int m=matrix[0].size();
      
     //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target) 
        return true;
        else if (matrix[row][col] < target) 
        low = mid + 1;
        else 
        high = mid - 1;
    }
    return false;

    }
};