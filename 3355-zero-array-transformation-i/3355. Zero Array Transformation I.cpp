class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {

        vector<int> lineSweep(nums.size()+1, 0);

        for(int i=0; i<q.size(); i++)
        {
            int st = q[i][0];
            int ed = q[i][1];

            lineSweep[st] += 1;
            lineSweep[ed+1] -= 1;
        }

        // for(auto it : lineSweep)cout<<it<<" ";

        // cout<<endl;

        for(int i=0; i<nums.size(); i++)
        {
            if(i>0)lineSweep[i] += lineSweep[i-1];

            if(nums[i] > lineSweep[i])return false;
        }

        // if(nums[0] >  lineSweep[0])return false;

        return true;
        
    }
};