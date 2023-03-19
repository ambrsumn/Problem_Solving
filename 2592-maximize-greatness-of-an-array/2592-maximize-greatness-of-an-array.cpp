class Solution {
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int j=0;
        int ans=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(j == i)j++;
            
            while(j <nums.size() && nums[j] <= nums[i])j++;
            
            if(j<nums.size())
            {
                ans++;
                j++;
            }
            else break;
            
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};