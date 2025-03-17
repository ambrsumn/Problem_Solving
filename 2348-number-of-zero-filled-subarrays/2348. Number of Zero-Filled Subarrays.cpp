class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        map<int, int> mpp;

        long long i=0, j=0, n=nums.size();
        bool foundZero = false;
        long long ans = 0;

        while(i<n)
        {

            if(nums[i] != 0 && foundZero)
            {
                long long total = (i - j);
                ans += (total * (total+1))/2;
                foundZero = false;
            }

            if(nums[i] == 0 && !foundZero)
            {
                j = i;
                foundZero = true;
            }

            i++;
        }

        if(foundZero)
        {
            long long total = (i - j);
            ans += (total * (total+1))/2;
            foundZero = false;
        }

        return ans;
        
    }
};