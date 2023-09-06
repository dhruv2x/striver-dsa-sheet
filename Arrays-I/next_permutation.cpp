class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        //  Approach 1

        //  If we are allowed to use exta space then we can 
        //  store all permutations of nums into vector
        //  search nums in vector and return i+1th is it's last element we can return vec[0]  
        //  TC  O(n!*n)     

        //  Approach 2

        //  Direct STL
        //  next_permutataion(nums.begin(),nums.end());
        //  return nums;
         
        //  Approach 3

        //  Ex 1,1,5
        //  1 1 5  1 5 1   5 1 1
        //  O(N*N) ->for all 3 steps

        //  Observations is prefix values are mostly same as nums
        //  just have to rearrange suffix elemenets
        //  Also next permutataion is greater then current one except for last permuatataion
        //  We can traverse from end to 0
        //  pick curr and check left side is there any element that is greater then curr
        //  if not i--
        //  else pick one with "just" greater then curr
        //  and swap in curr posistion rest all left side element
        //  put in sorted order 

        //  In simple words

        //  1. Pick curr where there is only 1 greater element present in left side
        //  2. Swap with that "just" greater element
        //  3. sort all left side elements

         //code

         //edge case

         /*
        
        bool islastpermute=true;
         for(int i=nums.size()-2;i>=0;i--)
         {
             //step 1
             int curr=nums[i];
             int ind=i,diff=INT_MAX;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>curr)
                {
                    //check diff
                    if(nums[j]-curr<diff)
                    {
                        ind=j;
                        diff=nums[j]-curr;
                    }   
                }
            }

            //Now step 2
            if(ind!=i)
            {
                swap(nums[ind],nums[i]);

                //Now step 3
                islastpermute=false;
                sort(nums.begin()+i+1,nums.end());
                break;
            }
         }
         if(islastpermute==true)
         {
            sort(nums.begin(),nums.end());
         }

         */


        //  Approach 4

        //  Now we do in O(3*N) complexity
        //  steps
        //  1 Find dip from end to begin
        //  2 if there is no deep reverse
        //  3 if there is find "just" greater then curr
        //  (Note from last to start first greate is always "Just" greate bcoz lefts side is sorted)
        //  4 Just reverse(O(n)) no need of sort(n*logn)


        //O(n)
        int ind=-1;
         for(int i=nums.size()-2;i>=0;i--)
         {
             if(nums[i]<nums[i+1])
             {
                 //there is dip
                 ind=i;
                 break;
             }
         }

         if(ind==-1)
         {
             reverse(nums.begin(),nums.end());
         }
        else
        {
            //O(n)
            int curr=nums[ind];
            for(int i=nums.size()-1;i>=ind;i--)
            {
                if(nums[i]>curr)
                {
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
            //O(N)
            reverse(nums.begin()+ind+1,nums.end());  
        }
             
    }
};