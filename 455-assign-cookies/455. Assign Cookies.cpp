class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end());
        int ans = 0;

        for(auto it : g)
        {
            if(s.size() == 0)return ans;
            if(it <= s.back())
            {
                ans++;
                s.pop_back();
            }
        }
        return ans;
    }
};