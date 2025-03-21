class Solution {
public:

    int dp[1001][1001];
    int recur(int i, int j, string &text1, string &text2)
    {
        if(i < 0 || j < 0)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int curr = 0;

        if(text1[i] == text2[j])
        {
            curr = 1 + recur(i-1, j-1, text1, text2);
        }

        else curr = max(recur(i-1, j, text1, text2), recur(i, j-1, text1, text2));

        return dp[i][j] = curr;
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(1001, vector<int>(1001, -1));

        return recur(text1.length()-1, text2.length()-1, text1, text2);
    }
};