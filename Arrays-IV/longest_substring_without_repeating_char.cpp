class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //Observtions

        /*
        Find longest substring without repeating characters
        example
        "pwwkew" 
         length of the longest substring = res 
         res -> 3 
        */

        //Brut Force Approch 1

        //TLE
        //746 / 987 testcases passed

        //Generate every possible substring 
        //claculate substring that have distinct characters
        //return max sized 
        
        /*
        int res=0,n=s.size();
        if(n==1)
        {
            return 1;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string temp="";
                if(j-i+1>0)
                {
                temp=s.substr(i,j-i+1);
                //Now calculate if it have distinct characters
                map<char,int>mp;
                bool isdistinct=true;
                for(auto ch:temp)
                {
                    mp[ch]++;
                }
                for(auto it:mp)
                {
                    if(it.second>=2)
                    {
                        isdistinct=false;
                        break;
                    }
                }
                int sz=temp.size();
                if(isdistinct==true && sz>0)
                {
                    res=max(res,sz);
                }
                }
            }
        }
        if(res==0 && n>0)   //[bbbb]
        return 1;
        else
        return res;
        */
        
        //Better Approach 2

        //using set
        //TC : O(n) & SC : O(n)
        
        if(s.size()==0)
        return 0;

        int maxans=INT_MIN;
    
        unordered_set<int>set;
        int l=0;
        
        for (int r = 0;r<s.length();r++) 
        {
          if (set.find(s[r]) != set.end()) //if duplicate found 
          {
              //delete all char from set
              //Between l to r
              //untill str[r] is not erased in map
            while (l < r && set.find(s[r]) != set.end()) 
            {
              set.erase(s[l]);
              l++;
            }
          }
          set.insert(s[r]);
          maxans = max(maxans, r - l + 1);
        }
        return maxans;

        //Optimized Approch 3
        /*
        
        Use sliding algo
        [pwwkew]
        distinct is pwke
        p -1
        w -1
        k -1
        e -1
        We also keep measuring start variable
        (start+1) defines starting point of substring

        Then we update each counter by 
        there latest index
        for example
        for pwwkew
        strat=-1
        p comes p counter=0 start=-1
        w comes w counter=1 start=-1
        When w comes again we update start 
        with its previous index
        w comes w counter=2 start=1
        .
        .
        .
        Size = i-start
        */

        //Code
        /*

        int n=s.size(),res=0;
        int start=-1;
        
        //we start character and its index in map
        unordered_map<char,int>mp;
        //set -1 to each distinct character
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==0)
            mp[s[i]]=-1;   
        }
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]!=-1)
            {
                //that means s[i] is repeated
                if(mp[s[i]]>start)
                start=mp[s[i]];
            }
            mp[s[i]]=i;
            res=max(res,i-start);
        }
        return res;
        */
    }
};