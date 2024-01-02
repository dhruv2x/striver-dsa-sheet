class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        //Brut Force O(n*n*n)

        //TLE : 308/312

        //code

        /*
        vector<vector<int>>ans;
        set<vector<int>>tempset;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(i<n && j<n && k<n)
                    {
                        vector<int>vec;
                        if(nums[i]+nums[j]+nums[k]==0)
                        {
                            vec.push_back(nums[i]);
                            vec.push_back(nums[j]);
                            vec.push_back(nums[k]);
                        }
                        sort(vec.begin(),vec.end());
                        if(!vec.empty())
                        tempset.insert(vec);
                    }
                }
            }
        }

        for(auto vectemp:tempset)
        {
          ans.push_back(vectemp);
        }
        return ans;
        */

        //Optimized  O(n*n*log(n))

        //(a+b+c)
        //Will use 2 loops for a and b
        //for c we use map to find -(a+b)
        //also make sure when use a and b decrease its freq
        //use set to remove duplicacy

        //code
        /*

        int n=nums.size();
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        //push into map first
        for(int i=0;i<n;i++)
        {
          mp[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
          mp[nums[i]]--;
          for(int j=i+1;j<n;j++)
          {
            mp[nums[j]]--;
            if(mp[-(nums[i]+nums[j])]!=0 && i<n && j<n)
            {
              //present
              vector<int>vec;
              vec.push_back(nums[i]);
              vec.push_back(nums[j]);
              vec.push_back(-(nums[i]+nums[j]));
              sort(vec.begin(),vec.end());
              if(!vec.empty())
              st.insert(vec);
            }
            mp[nums[j]]++;
          }
          mp[nums[i]]++;
        } 

        //push from set to final ans vector
        for(auto tempvec:st)
        {
          ans.push_back(tempvec);
        }
        return ans;
        */

        //Most Optimized APproch O(n*n)
        //without extra space

        //a+b+c=0
        //using for loop
        //pick a
        //for b & c use Two Pointer
        //find b+c = -(a) using two pointer
        //we also skip duplicates
        //for example nums[1,1,2,3]
        //Here for 1 we will enter into loop
        //But for second 1 we just move to next element

        //Code

        
        int n=nums.size();
        sort(nums.begin(),nums.end());  //Sort nums array
      vector<vector<int>>res;  
      //for a
      for(int i=0;i<n;i++)
      {
          if(i==0 || (i>0 && (nums[i]!=nums[i-1])))
          {
            //either 0th index
            //or unique element index

            //apply two pointer to find sum
            int l=i+1,r=n-1;
            int sum=0-nums[i];

            while(l<r)
            {
                if(nums[l]+nums[r]==sum)
                {
                  //found triplet
                  vector<int>vec;
                  vec.push_back(nums[i]);
                  vec.push_back(nums[l]);
                  vec.push_back(nums[r]);
                  res.push_back(vec);
                  
                  //Now we have to move l and r
                  //ex [-1,-1,-1,4,5,6]
                  //if l=0 & r=5 then we hve to move l=3

                  while(l<r && nums[l]==nums[l+1])
                  {
                    l++;
                  } 
                  //ex [2,3,4,6,6,6]
                  //if l=0 & r=5 then we hve to move r=2
                  while(l<r && nums[r]==nums[r-1])
                  {
                    r--;
                  } 
                  l++;
                  r--;
                }
                else if(nums[l]+nums[r]<sum)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }

          }
      }
        return res;
      
         
    }
};