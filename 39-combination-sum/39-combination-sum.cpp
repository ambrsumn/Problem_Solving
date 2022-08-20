class Solution {
public:
    
    vector<int> temp;
    vector<vector<int>> ans;
    
    void bt(int i, vector<int>& vec, int &tar, int sum)
    {   
        // cout<<sum<<endl;
        
        if(i>=vec.size())return;
        
        if(sum == tar)
        {
            ans.push_back(temp);
            return;
        }
        
        if(sum>tar)
            return;
        
        if(sum<tar)
        {
            temp.push_back(vec[i]);
            bt(i,vec,tar,sum+vec[i]);
            temp.pop_back();
        }
        
        bt(i+1,vec,tar,sum);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& vec, int tar) 
    {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        
        bt(0,vec,tar,0);
        
        return ans;
    }
};