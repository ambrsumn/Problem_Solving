class Solution {
public:

    bool isPossible(vector<int>& ranks, int cars, long long mid)
    {
        int carsRepaired = 0;

        for(int i=ranks.size()-1; i>=0; i--)
        {
            carsRepaired += sqrt(mid/ranks[i]);

            if(carsRepaired >= cars)return true;
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        if(ranks.size() == 1)
        {
            long long carsLL = static_cast<long long>(cars);  // Cast to long long
            long long ans = carsLL * carsLL * ranks[0];
            return ans;
        }

        sort(ranks.begin(), ranks.end());
        long long ans = 0;

        long long low = 1;
        long long high = 1e10;

        while(low <= high)
        {
            long long mid = low + (high-low)/2;

            // cout<<mid<<" mid"<<endl;

            if(isPossible(ranks, cars, mid))
            {
                // cout<<mid<<" ans"<<endl;
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};