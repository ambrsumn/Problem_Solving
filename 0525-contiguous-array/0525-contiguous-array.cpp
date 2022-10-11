class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int ans = 0;
        
        map<int,int> mpp;
        
        int sum=0;
        
        mpp[0]=-1;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            
            if(mpp.count(sum))
                ans = max(ans, i-mpp[sum]);
            
            else
                mpp[sum]=i;
        }
        
        return ans;
    }
};