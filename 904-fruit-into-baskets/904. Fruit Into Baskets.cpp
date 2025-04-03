class Solution {
public:
    int totalFruit(vector<int>& vec) {

        if(vec.size() <= 2)return vec.size();
        // set<int> st;

        // for(auto it : vec)st.insert(it);

        // if(vec.size() == st.size())return 2;

        // if(st.size() <= 2)return vec.size();

        // st.clear();

        vector<vector<int>> cal;

        int i = 0, n = vec.size();

        while(i < n)
        {
            int temp = 1;

            while(i+1<n && vec[i] == vec[i+1])
            {
                i++;
                temp++;
            }

            cal.push_back({vec[i], temp});
            i++;
        }

        if(cal.size() <= 2)return vec.size();

        int ans = 0;

        n = cal.size();
        i=1;

        while(i < n)
        {
            int prev = cal[i-1][0];
            int curr = cal[i][0];
            int sum = cal[i-1][1] + cal[i][1];

            i++;

            while(i < n && (cal[i][0] == prev || cal[i][0] == curr))
            {
                sum += cal[i][1];
                i++;
            }

            ans = max(ans, sum);
        }

        return ans;
        
    }
};