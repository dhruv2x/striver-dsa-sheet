
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;    //Will store result
        
        sort(nums.begin(),nums.end());  //Sort nums
        
        set<vector<int>>store;//will used to remove dupicate
        int n=nums.size();
        
        //Will use 4 pointers i,j,x,y
        //i=0 j=i+1 x=j+1 y=n-1
        //Storing 3 indices and end indices
        //First 2 for deciding new_target and 3rd and last for insertion by comparision
        
        //difference of target & (sum of i & j) will be new_target 
        //sum of x & y will be sum

        //TC : O(N*N*N)
        //i and j for O(N)
        //x and y combined O(N)
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //Use long for sumation and convert target to long
                //As per given constrain
                long long new_target=(long long)target-nums[i]-nums[j];
                //Used to chenck whether we have 2 value exist or not which have sum euqls to given new_target
                
                int x=j+1,y=n-1;
                
                while(x<y)
                {
                    long long sum=nums[x]+nums[y];
                    if(sum<new_target) 
                    {
                        x++;    //As we need larger value 
                        
                    }       
                    else if(sum>new_target)
                    {
                        y--;    //As we need smaller value 
                    }
                    else
                    {
                        //Insertion of values(Not sum) in set
                        
                        store.insert({nums[i],nums[j],nums[x],nums[y]});
                        //Now need to change both pointers
                        x++;
                        y--;
                        //i & j will change automaticly due to for loop
                        
                    }
                }
            }    
        }
        
        //Now insert in our main 2-D vector from set
        
        for(auto it:store)
        {
            res.push_back(it);
        }
        return res;
    }
    
    
};