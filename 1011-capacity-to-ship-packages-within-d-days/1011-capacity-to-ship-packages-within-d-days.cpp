class Solution {
public:
    
    bool isPossible(vector<int> vec, int mid, int days)
    {
        int count = 1;
        int curr=0;
        
        for(int i=0; i<vec.size(); i++)
        {
            curr += vec[i];
            
            if(mid < vec[i])
                return false;
            
            if(curr == mid)
            {
                count++;
                curr = 0;
            }
            
            else if(curr > mid)
            {
                count++;
                curr = vec[i];
            }
        }
        
        if(curr == 0)
            count--;
        
        if(count <= days)
            return true;
        
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int high = 1e9;
        
        // for(auto it : weights)
        //     high += it;
        
        // int low = *max_element(weights.begin(), weights.end());
        int low = 1;
        int ans = -1;
        
        cout<<low<<" "<<high<<endl;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            cout<<mid<<" ";
            
            if(isPossible(weights, mid, days))
            {
                cout<<"YES";
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
            
            cout<<endl;
        }
        
        return ans;
    }
};