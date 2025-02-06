class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        vector<vector<int>> ans;        
        int n = arr.size();
        
        if(n < 3)
            return ans;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<(n-2); i++)
        {
            if(i == 0 || (i>0 && arr[i] != arr[i-1]))
            {
            int j=(i+1);
            int k=(n-1);
            
            while(j<k)
            {
                if((arr[i]+arr[j]+arr[k]) == 0)
                {
                    vector<int> temp;
                    
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    
                    ans.push_back(temp);
                    
                    
                    while(j<k && (arr[j] == arr[j+1]))
                    {
                        j++;
                    }
                    
                    while(j<k && (arr[k] == arr[k-1]))
                    {
                        k--;
                    }  
                    
                    
                    j++;
                    k--;
                }
                
                else if((arr[i]+arr[j]+arr[k]) < 0)
                j++;
                
                else if((arr[i]+arr[j]+arr[k]) > 0)
                k--;
            }
                
            }
        }
        
        return ans;
    }
};