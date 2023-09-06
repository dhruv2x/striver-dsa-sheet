class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        //Observations

        //each integer is in the range [1, n] inclusive.
        //There is only one repeated number in nums

        //constrains
        //No extra space and no modifications

        //Approch 1

        //Use sorting and return arr[i]==arr[i+1]
        //O(n*log(n)) -> sort STL

        //Approch 2

        //Use Binary Search
        //TC : O(nlog(n))

        //Here as we know array is not sorted
        //but still
        //if count elements that is less than equals mid
        //and that count is less than equals to mid (not a mid element)
        //which means duplicates must be on left side
        //else go rigt side
        //return l

        //How?

        //Ex [1,3,4,2,2] -> l=0 r=4
        //mid=2 count of elemenst<=mid => 3
        //go right side

        //code

        
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            //count elements that is <=mid
            int cnt=0;
            for(auto n:nums)
            {
                if(n<=mid)
                {
                    cnt++;
                }
            }
            //Ex for mid=2 -> cnt=3
            if(cnt<=mid)
            {
                //go right side
                l=mid+1;
            }
            else
            {
                //go left
                r=mid;
            }
        }
        return l;

        //Approach 3


        //TC : O(n) and SC : O(n)
        //Create vector of n+1 size
        //store each eleemt at nums[i] and increase counter
        //if cnter at any index is 2 then return that nums[i]
        //else return length
        
        //Approach 4

        //TC : O(n) and SC : O(1)
        //Optimized Approch
        //But have to modify array

        //Whenever we are visiting any No 1st time, we will mark it as negative of it, and when we visit second time, we get a negative no and we simply return that no.

    //    int len = nums.size();
    //     for (int num : nums) 
    //     {
    //         int idx = abs(num);
    //         if (nums[idx] < 0) 
    //         {
    //             return idx;
    //         }
    //         nums[idx] = -nums[idx];
    //     }

    //     return len;

        
    }
};