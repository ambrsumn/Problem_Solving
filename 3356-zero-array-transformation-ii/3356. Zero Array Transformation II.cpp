class Solution {
public:

    bool isValid(vector<int>& nums, vector<vector<int>>& q, int k)
    {
        vector<int> lineSweep(nums.size()+1, 0);

        for(int i=0; i<k; i++)
        {
            int st = q[i][0];
            int ed = q[i][1];
            int val = q[i][2];

            lineSweep[st] += val;
            lineSweep[ed+1] -= val;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(i != 0) lineSweep[i] += lineSweep[i-1];
            if(nums[i] > lineSweep[i])return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {

        int ans = q.size()+1;
        int low = 0, high = q.size(), mid = 0;
        
        while(low <= high)
        {
            mid = low + (high-low)/2;

            if(isValid(nums, q, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        if(ans == q.size()+1)ans = -1;

        return ans;
    }
};