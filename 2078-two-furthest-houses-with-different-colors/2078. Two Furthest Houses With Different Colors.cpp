class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int ans = INT_MIN;
        int n = colors.size();

        for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++)if(colors[i] != colors[j])ans = max(ans, abs(j-i));

        return ans;
    }
};