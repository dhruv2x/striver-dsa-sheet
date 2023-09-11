class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //APproach 1 Brut Force O(n*n)
        /*
         for (int i = 0; i < n; i++) 
         {
            for (int j = i + 1; j < n; j++) 
            {
                if (arr[i] + arr[j] == target) return "YES";
            }
        }
             return "NO";
        */

        //Approch 2 using map
        
        //TC :  O(n)

        
         vector<int>ans;
      unordered_map<int,int>v;
       int n=nums.size();
       
        for(int i=0;i<n;i++)
        {   
              if(v.find(target-nums[i])!=v.end())
              {
                ans.push_back(i);
                ans.push_back(v[target-nums[i]]);
                break;
              }
             else
             {
               v[nums[i]]=i;
             }        
        }
         return ans;  
    

        //Approch 3 uisng two pointer

        //TC : O(n*n)

        /*

        int l=0,r=nums.size()-1,n=nums.size();
        vector<int>vec;
    
       for(int i=0;i<n;i++)
       {
           int sec=target-nums[i];
           for(int j=i+1;j<n;j++)
           {
               if(nums[j]==sec && i!=j)
               {
                   vec.push_back(i);
                   vec.push_back(j);
               }
           }
       }
       return vec;
       */

       //Approach 4 varient using two pointers

       //TC : O(n)+O(n*log(n)   

       /*
        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;
        while (left < right) 
        {
            int sum = arr[left] + arr[right];
            if (sum == target) 
            {
                return "YES";
            }
            else if (sum < target) 
            left++;
            else 
            right--;
        }
        return "NO";
       */ 
    }
};