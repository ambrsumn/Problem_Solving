class Solution {
public:
    int maxCandies(vector<int>& s, vector<int>& c, vector<vector<int>>& keys, vector<vector<int>>& boxes, vector<int>& i) {

        int n = s.size();
        vector<int> operated(n, -1);
        set<int> found, k;
        int ans = 0;
        queue<int> q;

        for(auto it : i)
        {
            if(s[it] == 1)q.push(it);
            else found.insert(it);
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            operated[curr] = 1;
            ans += c[curr];

            for(auto it : boxes[curr])
            {
                if(operated[it] == -1)
                {
                    if(s[it] == 1)q.push(it);
                    else found.insert(it);
                }
            }

            for(auto it : keys[curr])k.insert(it);

            for(auto it : found)
            {
                if(k.find(it) != k.end())
                {
                    q.push(it);
                    found.erase(it);
                }
            }
        } 

        return ans;

    }
};