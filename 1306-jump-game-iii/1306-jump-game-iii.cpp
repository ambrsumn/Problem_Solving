class Solution {
public:
    
    bool recur(int i, vector<int> &arr, vector<bool> &vis)
    {
        // cout<<i<<endl;
        
        if(i<0 || i>=arr.size())return false;
        if(vis[i])return false;
        if(arr[i] == 0)return true;
        
        vis[i]=true;
        
        bool way2=false, way1=false;
        
        // if(!vis[i+arr[i]])
        way2 = recur(i+arr[i], arr, vis);
        
        // if(!vis[i-arr[i]])
        way1 = recur(i-arr[i], arr, vis);
        
        return (way1 || way2);
        
    }
    bool canReach(vector<int>& arr, int start) 
    {
        vector<bool> vis(arr.size(), false);
        
        return recur(start, arr, vis);
    }
};