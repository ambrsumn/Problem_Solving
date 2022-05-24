class Solution {
public:
    
    bool isPossible(vector<int> arr, int mid)
    {
        int h=0, nh=0;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]>=mid)
                h++;
            
            else
                nh++;
        }
        
        if(h >= mid)
            return true;
        
        return false;
    }
    
    int hIndex(vector<int>& arr) 
    {
        
        int low = 0, high = arr.size();
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            cout<<mid<<" "<<endl;
            
            if(isPossible(arr, mid))
                {
                    ans = mid;
                    low = mid+1;
                }
            
            else
                high = mid-1;
        }
        
        return ans;
    }
};