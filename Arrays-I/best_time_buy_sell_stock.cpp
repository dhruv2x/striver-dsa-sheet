class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int max_pro=0,min_element=prices[0];
     
      //Keep traversing 
      //find min element till i
      //store profit in cur_pro and use cur and max trick
        
        for(int i=1;i<prices.size();i++)
        { 
          //As we have to maximize our profit
          //find minimum element till prices[i]
          
          min_element=min(min_element,prices[i]);   
          max_pro=max(max_pro,prices[i]-min_element);
        }
        return max_pro;
      
        
    }
};