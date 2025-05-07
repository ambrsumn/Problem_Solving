class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {

        sort(b.begin(), b.end());
        int ans = 0;

        map<int, vector<int>> x;
        map<int, vector<int>> y;

        for(auto it : b)
        {
            y[it[1]].push_back(it[0]);
            x[it[0]].push_back(it[1]);
        }

        // for(auto it : x)
        // {
        //     cout<<it.first<<" : ";

        //     for(auto itt : it.second)
        //     {
        //         cout<<itt<<" ";
        //     }
        //     cout<<endl;
        // }

        // for(auto it : y)
        // {
        //     cout<<it.first<<" : ";

        //     for(auto itt : it.second)
        //     {
        //         cout<<itt<<" ";
        //     }
        //     cout<<endl;
        // }

        for(auto it : b)
        {
            int xc = it[0];
            int yc = it[1];

            if(x[xc].size() < 3 ||
            yc <= x[xc][0] ||
            yc >= x[xc].back()
            )continue;

            if(y[yc].size() < 3 ||
            xc <= y[yc][0] ||
            xc >= y[yc].back()
            )continue;

            ans++;
        }
        return ans;
    }
};