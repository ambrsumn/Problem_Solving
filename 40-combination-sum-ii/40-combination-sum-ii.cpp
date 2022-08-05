class Solution {
public:
    
    vector<int> temp;
    set<vector<int>> ans;
    
    void bt(int i, vector<int>& vec, int &tar, int sum)
    {   
        if(sum == tar)
        {
            ans.insert(temp);
            return;
        }
        
        if(i >= vec.size())
          return;
        
        if(sum>tar)
            return;
        
        temp.push_back(vec[i]);
        sum += vec[i];
        
        bt(i+1,vec,tar,sum);
        
        temp.pop_back();
        sum -= vec[i];
        
        while(i+1<vec.size() && vec[i+1] == vec[i])i++;
        bt(i+1, vec, tar, sum);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& vec, int tar) 
    {
        sort(vec.begin(), vec.end());
        
        bt(0,vec,tar,0);
        
        vector<vector<int>> st;
        for(auto it : ans)
        {
            st.push_back(it);
        }
        
        return st;   
    }
};