class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {

        long long miniIndex = 0;
        long long mini = upper;
        long long maxi = lower;

        for(int i=0; i<d.size(); i++)
        {
            if(d[i] < mini)
                {
                    miniIndex = i+1;
                    mini = d[i];
                }
        }

        vector<long long> ans(d.size()+1, 0);
        ans[miniIndex] = lower;

        long long temp = miniIndex;
        temp = miniIndex-1;

        while(temp >= 0)
        {
            ans[temp] = ans[temp+1] - d[temp];
            temp--;
        }

        temp = miniIndex;
        //cout<<temp<<endl;

        while(temp < d.size())
        {
            // //cout<<temp<<" "<<d[temp]<<" "<<ans[temp-1]<<endl;
            ans[temp+1] = d[temp] + ans[temp];
            temp++;
        }

        mini = 1e9;
        maxi = -1e9;

        for(auto it : ans)
        {
            //cout<<it<<" ";
            maxi = max(maxi, it);
            mini = min(mini, it);
        }

        if(mini < lower)
        {
            for(int i=0; i<ans.size(); i++)
            {
                ans[i] += (lower - mini);
                maxi = max(maxi, ans[i]);
            }
        }
        //cout<<endl<< maxi<<endl;

        return (1 + upper - maxi) > 0 ? (1 + upper - maxi) : 0;

    }
};