class Solution {
public:
    int firstMissingPositive(vector<int>& arr) 
    {
        set<int> st;
        
        for(int i=0; i<arr.size(); i++)
        if(arr[i]>0)
        st.insert(arr[i]);
        
        int ans=-1, count=1;
        
        for(auto it : st)
        {
                if(count != it)
                {
                    ans=count;
                    break;
                }
                count++;
        }
        
        if(ans == -1)
        ans=count;
        
        return ans;
    }
};