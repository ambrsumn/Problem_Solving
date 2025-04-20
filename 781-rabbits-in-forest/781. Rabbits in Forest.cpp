class Solution {
public:
    int numRabbits(vector<int>& a) {

        int ans = 0;
        map<int, int> mpp;

        for(auto it : a)mpp[it]++;

        for(auto it : mpp)
        {
            if(it.first >= it.second)ans += (it.first+1);

            else 
            {
                ans += ((it.first+1) * (it.second/(it.first+1)));

                if(it.second%(it.first+1) != 0)ans += (it.first+1);
            }
        }

        return ans;
    }
};