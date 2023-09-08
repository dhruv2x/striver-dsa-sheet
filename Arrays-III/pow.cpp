class Solution {
public:
    double myPow(double x, int n) 
    {
        //Approach 1 Brut Force o(n)

        /*
        double ans = 1.0;
        for (int i = 0; i < n; i++) 
        {
            ans = ans * x;
        }
        return ans;
        */

        //Approach 1  TC : O(log(n))

        //Obeserve

        //2^10=(2*2)^5
        //2^5=2*(2^4)

        //so for n%2==0-> n=n/2 and x=x*x
        //and for n%2!=0 -> n=n-1 and x as it is

        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return x;
        }
        if(n<0)
        {
            n=abs(n);
            x=1/x;
        }
        if(n%2==0)
        return myPow(x*x,n/2);
        else
        return x*myPow(x,n-1);
        
    }
};