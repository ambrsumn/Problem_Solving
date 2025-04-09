class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        map<int,int> mpp;

        for(auto it : nums)mpp[it]++;
        reverse(nums.begin(), nums.end());

        int ans = 0;

        while(nums.size() >= 3)
        {
            bool duplicateFound = false;
            for(auto it : mpp)
            {
                if(it.second > 1)
                {
                    mpp[nums.back()]--;
                    nums.pop_back();

                    mpp[nums.back()]--;
                    nums.pop_back();

                    mpp[nums.back()]--;
                    nums.pop_back();

                    ans++;
                    duplicateFound = true;
                    break;
                }
            }

            if(!duplicateFound)break;
        }

        if(nums.size() == 2 && nums[0] == nums[1])ans++;

        return ans;
        
    }
};