class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        long long ans = -1;
        long long sum = 0;
        long long curr = 0;
        
        for(long long i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        
        long long mini = INT_MAX;
        
        for(long long i=0; i<nums.size(); i++)
        {
            curr += nums[i];
            sum -= nums[i];
            
            long long one = curr/(i+1);
            
            long long total = (nums.size()-i-1);
            if(total == 0)
                total = 1;
            
            long long two = sum/total;
            
            long long diff = abs(one-two);
            
            if(diff < mini)
            {
                ans = i;
                mini = diff;
            }
            
            // cout<<diff<<" ";
        }
        
        return ans;
    }
};