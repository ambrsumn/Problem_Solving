class Solution {
public:
    
    bool isPossible(vector<int> vec, long long mid, int m)
    {
        long long i = 0, n = vec.size(), curr=0;
        int count = 0;

        for(i=0; i<n; i++)
        {
            curr += vec[i];

            if(curr == mid)
            {
                curr = 0;
                count++;
            }

            else if (curr > mid)
            {
                curr = vec[i];
                count++;
            }
        }

        if(curr > 0)
        count++;

        if(count <= m)
        return true;

        return false;
    }
    
    
    int splitArray(vector<int>& a, int m) 
    {
        long long low = *max_element(a.begin(), a.end()), high = accumulate(a.begin(), a.end(), 0);
        
        long long ans = -1;
        
        while(low <= high)
        {
            long long mid = low + (high-low)/2;

            if(isPossible(a, mid, m))
            {
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }

        return ans;          
    }
};