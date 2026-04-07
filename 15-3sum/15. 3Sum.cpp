class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-2; i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                int currSum = nums[i]+nums[j]+nums[k];

                if(currSum == 0)
                {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                if(currSum > 0)
                {
                    k--;
                }

                if(currSum < 0)
                {
                    j++;
                }
            }
        }

        vector<vector<int>> ansVector;
        for(auto it : ans)ansVector.push_back(it);
        return ansVector;
    }
};