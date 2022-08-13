class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int i=0, curr=0, ans=INT_MIN, n=nums.size();
        
        while(i<n)
        {
            if(curr>=0)
            {
                curr += nums[i];
                i++;
                ans = max(ans,curr);
            }
            else
                curr=0;
        }
        
        return ans;
    }
};