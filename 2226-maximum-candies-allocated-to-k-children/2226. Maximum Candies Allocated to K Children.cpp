class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        sort(candies.begin(), candies.end());
        reverse(candies.begin(), candies.end());


        long long totalCandies = 0, ans = 0;
        for(auto it : candies)totalCandies += it;

        if(totalCandies < k)return ans;
        if(totalCandies == k)return 1;

        long long low = 1, high = candies[0];

        while(low <= high)
        {
            long long mid = low + (high-low)/2;
            bool isPossible = true;
            long long maxBatches = 0;

            for(auto it : candies)
            {
                if(it < mid)
                {
                    isPossible = false;
                    break;
                }
                else
                {
                    maxBatches += it/mid;
                    if(maxBatches >= k)
                    {
                        break;
                    }
                }
            }

            if(maxBatches < k)isPossible = false;

            if(isPossible)
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
    }

        return ans;
    }
};