class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {

        long long ans = 0;
        map<int, int> mpp;
        long long fullDays = 0;

        for(auto it : hours)
        {
            if(it%24 == 0)fullDays++;
            else mpp[it%24]++;
        }

        for(auto it : mpp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }

        for(auto it : hours)
        {
            if(it%24 == 0)continue;

            else
            {
                int remaining = 24 - (it%24);

                if(remaining == 12)
                {
                    mpp[12]--;
                    if(mpp[12] > 0)ans += mpp[12];
                }
                else
                {
                    if(mpp[remaining] > 0)ans += mpp[remaining];

                    mpp[it%24]--;
                }
            }
        }

        ans += ((fullDays-1)*fullDays)/2;

        return ans;
        
    }
};