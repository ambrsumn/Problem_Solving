class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char, int> mpp;
        int i=0;
        vector<int> ans;

        for(int i=0; i<s.length(); i++) mpp[s[i]] = max(mpp[s[i]], i);

        // for(auto it : mpp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<endl;

        while(i<s.length())
        {
            int j=i;
            int till = mpp[s[i]];

            while(j <= till)
            {
                till = max(till, mpp[s[j]]);
                j++;
            }

            // cout<<i<<" "<<till<<" "<<j<<endl;

            ans.push_back((till - i + 1));
            i = j;
        }

        return ans;
    }
};