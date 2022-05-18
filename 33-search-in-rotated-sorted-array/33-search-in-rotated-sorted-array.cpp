class Solution {
public:
    
int mid_pos(vector<int> arr, int n)
{
    int key = arr[0];
    int ans=-1;

    int low=0, high=(n-1);

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] >= key)
        {
            key = arr[mid];
            low = mid+1;
        }

        else
        {
            key = arr[mid];
            ans = mid;
            high = mid-1;
        }
    }

    if(ans == -1)
    ans = 0;

    return ans;
}
    
    
    int binary_search(vector<int> arr, int loww, int highh, int target)
    {
        int low = loww, high = highh;
        
        cout<<low<<" "<<high<<endl;
        int ans=-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target)
            {
                ans = mid;
                break;
            }
            
            else if(arr[mid] < target)
                low = mid+1;
            
            else
                high = mid-1;
        }
        
        cout<<"ans i s"<<ans<<endl;
        return ans;
    }
    
    
    int search(vector<int>& arr, int target) 
    {
        int n = arr.size();
        
        int indx = mid_pos(arr, n);
        
        
        cout<<indx<<endl;
        
        if(arr[indx] == target)
            return indx;
        
        if(indx == 0)
            return binary_search(arr,0, n-1, target);
        
        else
        {
            int next = (indx+1)%n;
            int prev = (indx+n-1)%n;
            
            if(target >= arr[0])
                return binary_search(arr, 0, prev, target);
            
            else
                return binary_search(arr, next, (n-1), target);
        }
        
        return -1;
    }
};