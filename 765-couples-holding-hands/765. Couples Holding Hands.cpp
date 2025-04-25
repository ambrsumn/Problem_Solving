class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        map<int, int> mpp;
        int idx=0, ans=0;

        for(auto it : row)
        {
            mpp[it] = idx;
            idx++;
        }

        // for(auto it : mpp)cout<<it.first<<" "<<it.second<<endl;
        // cout<<endl;

        for(int i=0; i<row.size()-1; i+=2)
        {
            int partner = -1;
            if(row[i]%2 == 0)partner = row[i]+1;
            else partner = row[i]-1;

            if(row[i+1] != partner)
            {
                mpp[row[i+1]] = mpp[partner];
                swap(row[i+1], row[mpp[partner]]);
                ans++;
            }
        }

        // for(auto it : mpp)cout<<it.first<<" "<<it.second<<endl;

        return ans;
    }
};