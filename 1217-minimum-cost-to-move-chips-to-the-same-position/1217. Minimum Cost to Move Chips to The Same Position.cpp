class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {

        int ans = INT_MAX, n=p.size();

        for(int i=0; i<n; i++)
        {
            int curr = 0;
            for(int j=0; j<n; j++)
            {
                if(j == i)continue;

                if(p[i]%2 != p[j]%2)curr += 1;
            }

            ans = min(ans, curr);
        }
        return ans;
    }
};