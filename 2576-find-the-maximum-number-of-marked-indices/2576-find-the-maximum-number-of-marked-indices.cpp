class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()/2;
        int ans=0;
        
        
        while(i<nums.size()/2 && j<nums.size())
        {
            if(2*nums[i] <= nums[j])
            {
                ans++;
                i++;
            }
            
            j++;
        }
        
        return ans*=2;
    }
};