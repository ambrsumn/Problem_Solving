class Solution {
public:
    int n=0;
    
//     int rob(int i, vector<int> &nums, vector<int> &dp)
//     {
//         if(i<0)return 0;
//         if(i==0)return nums[0];
        
//         if(dp[i] != -1)return dp[i];
        
//         int left = nums[i] + rob(i-2, nums, dp);
//         int right = rob(i-1, nums, dp);
        
//         return dp[i] = max(left,right);
//     }
    
    int rob(vector<int>& nums) 
    {
        n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n+1, -1);
        int ans1=0, ans2=0;
        
        //LEAVING THE LAST HOUSE
        dp[0]=nums[0];
        for(int i=1; i<n-1; i++)
        {
            int left = nums[i];
            if(i-2 >= 0)left += dp[i-2];
            
            int right = dp[i-1];
            
            dp[i] = max(left,right);
        }
        
        ans1 = dp[n-2];
        
        //leaving the first house
        
        for(int i=1; i<n; i++)
        {
            int left = nums[i];
            if(i-2 > 0)left += dp[i-2];
            
            int right = 0;
            if(i-1 > 0)right += dp[i-1];
            
            dp[i] = max(left,right);
        }
        ans2 = dp[n-1];
        
        cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
        
    }
};