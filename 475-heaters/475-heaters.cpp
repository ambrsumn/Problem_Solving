class Solution {
public:
    
    bool isPossible(vector<int> houses, vector<int> heaters, int mid)
    {
        int n = houses.size();
        int m = heaters.size();
        int i=0, j=0;
        
        while(i<n && j<m)
        {
            if(abs(houses[i] - heaters[j]) <= mid)
            {
                i++;
            }
            
            else
                j++;
        }
        
        if(i == n && j <= m)
            return true;
        
        return false;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int low = 0, high = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
        long long ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(isPossible(houses, heaters, mid))
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