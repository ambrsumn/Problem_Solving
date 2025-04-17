class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        long long i=0, j=0, n=nums.size(), count=0, ans=0, temp=0;
        map<int, int> mpp;

        while(j < n)
        {
            long long prev = mpp[nums[j]];
            mpp[nums[j]]++;
            long long curr = mpp[nums[j]];

            count = count - ((prev * (prev-1))/2) + ((curr * (curr-1))/2);

            if(count >= k)ans += (n-j);

            while(count >= k && i<j)
            {
                prev = mpp[nums[i]];
                mpp[nums[i]]--;
                curr = mpp[nums[i]];

                count = count - ((prev * (prev-1))/2) + ((curr * (curr-1))/2);

                if(count >= k)ans += (n-j);

                i++;
            }

            j++;
        }

        return ans;
    }
};