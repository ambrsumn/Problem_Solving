class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> st;
    
    void bt(int &k, int &n, int i)
    {
        if(temp.size()==k)
        {
            st.insert(temp);
            return;
        }
        
        if(i>n)return;
        
        temp.push_back(i);
        bt(k,n,i+1);
        temp.pop_back();
        
        bt(k,n,i+1);
        
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        bt(k,n,1);
        
        for(auto it : st)
            ans.push_back(it);
        
        return ans;
    }
};