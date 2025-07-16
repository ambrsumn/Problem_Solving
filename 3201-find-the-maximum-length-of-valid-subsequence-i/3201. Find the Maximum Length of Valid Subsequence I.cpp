class Solution {
public:

    int countLength(vector<int> &nums, string startWith)
    {
        int count=0;
        bool findNext;
        if(startWith == "odd")findNext = 1;
        else findNext = 0;

        for(auto it : nums)
        {
            if(it == findNext)
            {
                count++;
                findNext == 0 ? findNext = 1 : findNext = 0;
            }
        }

        return count;
    } 

    int maximumLength(vector<int>& nums) {
        
        int n = nums.size();
        int even=0, odd=0;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            nums[i] %= 2;
            if(nums[i]%2 == 0)even++;
            else odd++;
        }

        ans = max(even, odd);

        int other = max(countLength(nums, "odd"), countLength(nums, "even"));
        ans = max(ans, other);

        return ans;

    }
};