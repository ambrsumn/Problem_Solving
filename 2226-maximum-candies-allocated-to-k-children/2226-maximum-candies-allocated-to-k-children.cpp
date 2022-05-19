class Solution
{
public:
    bool isPossible(vector<int> vec, int mid, long long k)
    {
        long long count = 0;
        
        for (int i = 0; i < vec.size(); i++)
        {
            int ele = vec[i] / mid;
            count += ele;
        }

        if (count >= k)
            return true;

        return false;
    }

    int maximumCandies(vector<int> &candies, long long k)
    {
        int ans = 0, low = 1;
        int high = *max_element(candies.begin(), candies.end());
        
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // cout<<mid<<" ";
            
                if (isPossible(candies, mid, k))
                {
                    // cout<<"YES"<<endl;
                    ans = mid;
                    low = mid + 1;
                }

                else
                    high = mid - 1;
            
            // cout<<endl;
        }

        return ans;
    }
};