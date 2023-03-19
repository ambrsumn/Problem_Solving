class Solution {
public:
    int distMoney(int money, int children) 
    {
        if(money < children)return -1;
        
        money -= children;  
        int ans = money/7;
        int rem = money%7;
        
        if(ans == children && rem == 0)return ans;
        
        if(ans >= children)
        {
            return children-1;
        }
        
        if(rem==3 && (children - ans == 1))return ans-1;
        
        return ans;
    }
};