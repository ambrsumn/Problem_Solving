class Solution {
public:
    int maxSum(vector<int>& nums) {

        set<int> st;
        int ans = 0;
        int maxi = INT_MIN;

        for(auto it : nums)
        {
            if(it > 0)st.insert(it);
            else
            {
                maxi = max(it, maxi);
            }
        }

        if(st.size() == 0)return maxi;

        for(auto it : st)ans += it;

        return ans;
        
    }
};