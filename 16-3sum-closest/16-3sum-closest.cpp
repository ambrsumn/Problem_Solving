class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int ans = INT_MIN;
        int def = INT_MAX;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int flag=0;
        for(int i=0; i<n-2; i++)
        {
            int j=i+1, k=n-1;
            int sum=0;
            while(j<k)
            {
                sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target-sum);
                // cout<<i<<" "<<j<<" "<<k<<" "<<sum<<endl;
                
                if(diff<def)
                {
                    def = diff;
                    ans = sum;
                }
                
                if(sum == target)
                {
                    flag=1;
                    break;
                }
                
                if(sum < target)j++;
                if(sum > target)k--;
            }
            
            if(flag)break;
        }
        
        return ans;
    }
};