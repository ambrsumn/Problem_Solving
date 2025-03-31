class Solution {
public:
    int reverseDegree(string s) {

        int ans = 0;

        int idx = 1;
        for(auto it : s)
        {
            ans += (26 - (it-'a'))*idx;
            idx++;
        }

        return ans;
        
    }
};