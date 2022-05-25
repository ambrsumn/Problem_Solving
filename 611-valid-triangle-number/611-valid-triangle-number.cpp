class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        if(nums.size() == 1 || nums.size() == 2)
            return 0;
        
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(int i=0; i<nums.size()-2; i++)
        {
            for(int j=i+1; j<nums.size()-1; j++)
            {
                int key = nums[i]+nums[j];
                
                int indx = (lower_bound(nums.begin()+(j+1), nums.end(), key) - nums.begin());
                
                if(indx == nums.size())
                    ans += (nums.size()-1-j);
                
                else
                ans += (indx-j-1);
            }
        }
        
        return ans;
    }
};