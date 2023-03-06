class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        long long count=1;
        long long ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(k != 0 && count < nums[i])
            {
                // cout<<k<<" "<<count<<" "<<nums[i]<<" ";
                
                if(k - (nums[i]-count) >= 0)
                {
                k -= (nums[i]-count);
                count--; 
                long long temp = (nums[i]-1);
                long long s1 = ((count*(count+1))/2);
                long long s2 = ((temp*(temp+1))/2);
                
                ans += (s2-s1);
                }
                
                else
                {
                    count--;
                    long long temp = (count+k);
                    long long s1 = ((count*(count+1))/2);
                    long long s2 = ((temp*(temp+1))/2);
                    k=0;
                    
                    ans += (s2-s1);
                }

                // cout<<ans<<endl;
            }
            
            count=nums[i]+1;
        }
        
        if(k != 0)
        {
            count--;
            long long temp = count+k;
            
            long long s1 = ((count*(count+1))/2);
            long long s2 = ((temp*(temp+1))/2);
            
            ans += (s2-s1);
        }
        
        return ans;
    }
};