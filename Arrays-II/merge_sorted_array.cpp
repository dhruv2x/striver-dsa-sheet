class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        //Approach 1 Wemay do easily with O(m+n) space and TC : O(n+m)
        //Approach 2 add nums2 in nums1 and sort nums1 O(n*log(n))
        //Approach 3 Without space and In O(max(m+n))

        //set i and j at m-1 and n-1 and k at end of the nums1
        //Just traverse nums2 
        //Store greater value at nums1[k] and k-- and respective i or j


        //Dry Run
        //initially nums1[i] & nums2[j] is 3 and 6
        //as nums1[i]<nums2[j] -> store 6 in nums1[k],nums1:1 2 3 0 0 6
        //Now we have 3 and 5 ->. store 5 in nums1[k],nums1:1 2 3 0 5 6
        //Now we have 3 and 2 -> store 2 in nums1[k],nums1:  1 2 3 3 5 6
        //Now we have 2 and 2 -> store 2 in nums1[k],nums1: 1 2 2 3 5 6 
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) 
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            } 
            else 
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

       
    }
};