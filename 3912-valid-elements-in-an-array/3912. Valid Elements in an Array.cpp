class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++)
            {
                if(i==0||i==n-1)
                {
                vec.push_back(nums[i]);
                continue;
                }
            
        bool left=true;
        bool right=true;
        for(int j=0;j<i;j++)
            {
                if(nums[i]<=nums[j])
                {
                    left=false;
                    break;
                }
            }
        for(int j=i+1;j<n;j++)
            {
                if(nums[i]<=nums[j])
                {
                    right=false;
                    break;
                }
            }
        if(left||right)
        {
            vec.push_back(nums[i]);
        }
            }
        return vec;
        
    }
};