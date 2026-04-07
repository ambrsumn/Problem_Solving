class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int ans = 0;
        int closest = INT_MAX;

        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    int sum = nums[i]+nums[j]+nums[k];

                    if( abs(sum - target) < closest )
                    {
                        ans = sum;
                        closest = abs(sum - target);
                    }
                }
            }
        }

        return ans;
        
    }
};