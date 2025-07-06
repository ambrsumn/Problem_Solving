class Solution {
public:

    int calculateMaxSeats(vector<int> &bs)
    {
        //check for seat 2
        auto it = lower_bound(bs.begin(), bs.end(), 2);
        int nextSeat = 0;
        if(it != bs.end())nextSeat = *it;

        if(nextSeat > 9 || nextSeat == 0)return 2;
        else if(nextSeat > 5)return 1;

        else if(nextSeat <= 5)
        {
            //check for seat 4
            it = lower_bound(bs.begin(), bs.end(), 4);
            nextSeat = 0;
            if(it != bs.end())nextSeat = *it;

            if(nextSeat > 7 || nextSeat == 0)return 1;

            else if(nextSeat <= 5)
            {
                //check for seat 6
                it = lower_bound(bs.begin(), bs.end(), 6);
                nextSeat = 0;
                if(it != bs.end())nextSeat = *it;

                if(nextSeat > 9 || nextSeat == 0)return 1;
            }
        }

        return 0;
    } 

    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {

        int ans = 0;
        map<int, vector<int>> mpp;
        sort(r.begin(), r.end());

        for(auto it : r)mpp[it[0]].push_back(it[1]);

        for(auto it : mpp)ans += calculateMaxSeats(it.second);

        ans += (n - mpp.size())*2;

        return ans;
    }
};