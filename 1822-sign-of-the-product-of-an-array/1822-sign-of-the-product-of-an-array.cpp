class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int neg = 0;
        int zero=0;
        
        for(auto it : nums)
        {
            if(it < 0)neg++;
            if(it == 0)zero++;
        }
        
        if(zero > 0)return 0;
        
        if(neg == 0)return 1;
        
        if(neg%2 == 0)return 1;
        
        return -1;
    }
};