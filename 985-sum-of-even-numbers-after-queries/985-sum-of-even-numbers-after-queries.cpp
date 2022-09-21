class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) 
    {
        int sum=0;
        vector<int> ans;
        
        for(auto it : nums)
            if(it%2 == 0)sum += it;
        
        
        for(int i=0; i<q.size(); i++)
        {
            if(nums[q[i][1]]%2 == 0)sum -= nums[q[i][1]];
            nums[q[i][1]] += q[i][0];
            if(nums[q[i][1]]%2 == 0)sum += nums[q[i][1]];
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};