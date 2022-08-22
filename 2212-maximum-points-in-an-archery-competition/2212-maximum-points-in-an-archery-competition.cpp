class Solution {
public:
    
    int ans = INT_MIN;
    vector<int> tempp;
    int total=0;
    
    void recur(int i, int t, vector<int> &arr, int temp, vector<int> &anss)
    {
        // cout<<temp<<" "<<t<<" "<<arr[i]<<endl;
        
        if((i<0 && t>=0) || t==0)
        {
            // temp = anss;
            if(ans < max(ans,temp))
            {
                for(int j=0; j<12; j++)
                {
                    // sum += anss[j];
                    tempp[j]=anss[j];
                }
                tempp[0]+= t;
                // cout<<t<<endl;
            }
            
            ans = max(ans,temp);
            
            return;
        }
        
        else if(i<0)return;
        
        //TAKE
        if(t>=arr[i])
        {
            anss[i] = arr[i]+1;
            
            recur(i-1, (t-arr[i]-1), arr, temp+i, anss);
            anss[i]=0;
        }
        
        //LEAVE
        recur(i-1, t, arr, temp, anss);
    }
    
    vector<int> maximumBobPoints(int t, vector<int>& arr) 
    {
        tempp.resize(12, 0);
        vector<int> anss(12, 0);
        recur(11,t,arr,0, anss);
        
        return tempp;
    }
};