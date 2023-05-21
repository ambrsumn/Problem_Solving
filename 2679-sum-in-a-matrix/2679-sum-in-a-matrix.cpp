class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sort(nums[i].begin(), nums[i].end());
        }
        
        int n = nums[0].size();
        
        for(int i=0; i<n; i++)
        {
            // cout<<i<<endl;
            int temp = INT_MIN;
            
            for(int j=0; j<nums.size(); j++)
            {
                temp = max(temp, nums[j].back());
                nums[j].pop_back();
            }
            // cout<<temp<<endl;
            ans += temp;
        }
        
        return ans;
    }
};