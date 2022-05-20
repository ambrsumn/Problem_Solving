class Solution
{
public:
    int low, high;
    
    int binarySearch(vector<int> arr, int x)
    {
        while (high >= low)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                high = mid - 1;

            else
                low = mid + 1;
        }
        return -1;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        
        //APPLYING BINARY SEARCH
        
        low=0; high = n-1;
        int indx = binarySearch(arr, x);
        
        //CREATING PRIORITY QUEUE - MIN
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // ELEMENT FOUND IN THE ARRAY
        
        if(indx != -1)
        {
            pq.push(arr[indx]);
            int i = indx-1, j = indx+1;
            
            while(pq.size() != k)
            {
                if(i>=0 && j<=n-1)
                {
                    if(abs(x - arr[i]) < abs(x - arr[j]))
                    {
                        pq.push(arr[i]);
                        i--;
                    }
                    
                    else if(abs(x - arr[i]) > abs(x - arr[j]))
                    {
                        pq.push(arr[j]);
                        j++;
                    }
                    
                    else
                    {
                        pq.push(arr[i]);
                        i--;
                    }
                }
                
                else if(i>= 0)
                {
                    pq.push(arr[i]);
                    i--;
                }
                
                else
                {
                    pq.push(arr[j]);
                    j++;
                }
            }
            
        }
        
        //ELEMENT NOT FOUND IN THE ARRAY
        
        else
        {
            int i = min(low, high), j = max(low, high);

            while(pq.size() != k)
            {
                if(i>=0 && j<=n-1)
                {
                    if(abs(x - arr[i]) < abs(x - arr[j]))
                    {
                        pq.push(arr[i]);
                        i--;
                    }
                    
                    else if(abs(x - arr[i]) > abs(x - arr[j]))
                    {
                        pq.push(arr[j]);
                        j++;
                    }
                    
                    else
                    {
                        pq.push(arr[i]);
                        i--;
                    }
                }
                
                else if(i>= 0)
                {
                    pq.push(arr[i]);
                    i--;
                }
                
                else
                {
                    pq.push(arr[j]);
                    j++;
                }
            }
            
        }
        
        // INSERTING THE PRIORITY QUEUE ELEMENTS IN THE VECTOR
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
        
    }
};