class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        map<int, set<int>> mpp;
        map<int, int> ball;

        vector<int> ans;

        for(int i=0; i<queries.size(); i++)
        {
            auto it = ball.find(queries[i][0]);

            if(it != ball.end())
            {
                int color = it->second;

                mpp[color].erase(it->first);
                if(mpp[color].size() == 0)
                {
                    mpp.erase(color);
                }
            }

            mpp[queries[i][1]].insert(queries[i][0]);
            ball[queries[i][0]] = queries[i][1];

            ans.push_back(mpp.size());
        }

        return ans;
        
    }
};