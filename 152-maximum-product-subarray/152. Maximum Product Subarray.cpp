class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int curr=1;
        int maxlr=-100000;
        int maxrl=-100000;
        
        
        for(int i=0; i<nums.size(); i++)
        {
            curr *= nums[i];
            
            if(curr > maxlr)
                maxlr = curr;
            
            if(curr == 0)
                curr = 1;
        }
        
        curr=1;
        
        for(int i=(nums.size()-1); i>=0; i--)
        {
            curr *= nums[i];
            
            if(curr > maxrl)
                maxrl = curr;
            
            if(curr == 0)
                curr = 1;
        }        
        
        return max(maxlr, maxrl);
    }
};