class Solution {
public:
    string findCommonResponse(vector<vector<string>>& r) {

        set<string> st;
        map<string, int> mpp;
        string ans = "";
        int maxi = -1;

        for(auto it : r)
        {
            st.clear();

            for(auto itt : it)st.insert(itt);

            for(auto itr : st)
            {
                mpp[itr]++;

                if(mpp[itr] > maxi)
                {
                    maxi = mpp[itr];
                    ans = itr;
                }

                else if(mpp[itr] == maxi && ans > itr)
                {
                    ans = itr;
                }
            }
        }

        return ans;
        
    }
};