class Solution {
public:
    int majorityElement(vector<int>& nums) {

        map<int, int> mpp;

        for(auto it : nums)
        {
            mpp[it]++;
        }
        int ans = -1;
        int counter = -1;

        for(auto it : mpp)
        {
            if(it.second > counter)
            {
                counter = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};