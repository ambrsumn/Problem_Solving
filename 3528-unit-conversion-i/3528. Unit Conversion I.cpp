class Solution {
public:

    int mod = 1e9+7;
    map<int, vector<int>> mpp;

    int solve(int i, vector<int> &answer)
    {
        int ans = 1;
        if(mpp[i][0] == 0)
        {
            // ans = ((ans%mod)*(mpp[i][1]%mod)%mod);
            ans = (1LL * ans * mpp[i][1]) % mod;
            answer[i] = ans;
        }

        else 
        {
            if(answer[mpp[i][0]] != -1)
            {
                // ans = ((mpp[i][1]%mod)*(answer[mpp[i][0]] %mod)%mod);
                ans = (1LL * mpp[i][1] * answer[mpp[i][0]]) % mod;

                answer[i] = ans;
            }
            else
            {
                // ans = ((mpp[i][1]%mod)*(solve(mpp[i][0], answer)%mod)%mod);
                ans = (1LL * mpp[i][1] * solve(mpp[i][0], answer)) % mod;
                answer[i] = ans;
                
            }
        }
        return answer[i];
    }

    vector<int> baseUnitConversions(vector<vector<int>>& c) {

        vector<int> answer(c.size()+1, -1);
        answer[0]=1;

        for(auto it : c)mpp[it[1]] = {it[0], it[2]};

        for(int i=1; i<=c.size(); i++)
        {
            if(answer[i] == -1)solve(i, answer);
        }

        return answer;
    }
};