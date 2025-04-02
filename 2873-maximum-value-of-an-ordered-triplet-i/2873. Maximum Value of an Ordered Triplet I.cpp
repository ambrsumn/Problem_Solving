class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        long long ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    long long l = nums[i];
                    long long m = nums[j];
                    long long n = nums[k];

                    long long curr = (l-m)*n;
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};