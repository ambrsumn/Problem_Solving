class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) 
    {
        int i=0, j=(arr.size()-1);
        
        sort(arr.begin(), arr.end());
        
        int ans=0;
        
        while(i<j)
        {
            int curr = (arr[i]+arr[j]);
            
            if(curr <= limit)
            {
                ans++;
                j--;
                i++;
            }
            
            else
            {
                ans++;
                j--;
            }    
        }
        
        if(i == j)
            ans++;
        
        return ans;
    }
};