class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        //Measure 0,1,2
        //And update nums
         /*  
        int cnt_0=0,cnt_1=0,cnt_2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cnt_0++;
            }
            else if(nums[i]==1)
            {
                cnt_1++;
            }
            else if(nums[i]==2)
            {
                cnt_2++;
            }
        }

        int j=0;
        while(cnt_0>0)
        {
            nums[j]=0;
            cnt_0--;
            j++;
        }
        
        while(cnt_1>0)
        {
            nums[j]=1;
            cnt_1--;
            j++;
        }
        
        while(cnt_2>0)
        {
            nums[j]=2;
            cnt_2--;
            j++;
        }
        */
        //All sorting algo
        //Use Bubble sort
        //TC O(n*n) inplace stable
        
        /*
        int n=nums.size();
        bool isswaped=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    isswaped=true;
                    swap(nums[j],nums[j+1]);
                }
            }
            if(isswaped=false)
            {
                break;
            }
        }
        */
        

        //Selection Sort
        /*
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            int min_ind=i;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<curr)
                {
                    min_ind=j;
                    curr=nums[j];
                }
            }
            if(i!=min_ind)
            {
                swap(nums[i],nums[min_ind]);
            }
        }
        */

        //Insertion sort
        //pick curr and compare with all left
        //move right side

        // int n=nums.size();
        // for(int i=1;i<n;i++)
        // {
        //     int curr=nums[i];
        //     int j=i-1;
        //     while(j>=0 && nums[j]>curr)
        //     {
        //         nums[j+1]=nums[j];
        //         j--;
        //     }
        //     nums[j+1]=curr;
        // }
        

        //Optimal Algo in O(n) using 3 Pointers

        //3 case if 
        // num[mid]==0 -> swap with low, low++ and mid++    
        // nums[mid]==1 -> mid++
        // nums[mid]==2 -> swap with high, high-- do not move mid as we still need to sort mid element  

        int n=nums.size();
        int low=0,mid=0,high=n-1; 

        while (mid <= high) 
        {
            if (nums[mid] == 0) 
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }   
            else if (nums[mid] == 1) 
            {
                mid++;
            }
            else 
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }         
    }
};