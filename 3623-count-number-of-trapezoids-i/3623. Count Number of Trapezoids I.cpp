class Solution {
public:
    int waysToChoose(int n)
    {
        int ans = 0;
        for(int i=n-1; i>=1; i--)
        {
            ans += i;
        }

        return ans;
    }
    int countTrapezoids(vector<vector<int>>& points) {

        map<int, int> mpp;
        vector<int> vec;
        
        for(auto it : points)mpp[it[1]]++;

        for(auto it : mpp)
        {
            if(it.second >= 2)vec.push_back(waysToChoose(it.second));
        }
        int ans = 0;
        int mod = 1e9 + 7;

        // for(auto it : vec)cout<<it<<" ";
        cout<<vec.size()<<endl;
        if(vec.size() < 2)return 0;
        long long preSum = 0;
        for (int it : vec) preSum = (preSum + it) % mod;
        
        for (int it : vec) {
            preSum = (preSum - it + mod) % mod;
            ans = (ans + 1LL * it * preSum % mod) % mod;
        }
        return ans;
    }
};