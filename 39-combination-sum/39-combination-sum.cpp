class Solution {
public:
    
    vector<int> temp;
    vector<vector<int>> ans;
    
    void bt(int i, vector<int>& vec, int &tar, int sum)
    {   
        if(sum == tar)
        {
            ans.push_back(temp);
            return;
        }
        
        if(sum>tar)
            return;
        
        while(i<vec.size())
        {
            temp.push_back(vec[i]);
            sum += vec[i];
            bt(i,vec,tar,sum);
            sum -= vec[i];
            i++;
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& vec, int tar) 
    {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        
        bt(0,vec,tar,0);
        
        return ans;
    }
};