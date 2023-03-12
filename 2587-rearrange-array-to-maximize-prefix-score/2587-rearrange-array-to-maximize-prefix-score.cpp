class Solution {
public:
    int maxScore(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        
        long long curr = 0, ans=0;
        
        for(auto it : nums)
        {
            curr += it;
            if(curr > 0)ans++;
            else break;
        }
        
        return ans;
    }
};