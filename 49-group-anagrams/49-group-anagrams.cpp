class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,int> mpp;
        
        int count=0;
        
        for(auto it : strs)
        {
            string temp = it;
            sort(temp.begin(), temp.end());
            
            if(!mpp.count(temp))
            {
                mpp[temp]=count;
                count++;
            }
        }
        
        vector<vector<string>> ans(count);
        
        for(auto it : strs)
        {
            string temp = it;
            sort(temp.begin(), temp.end());
            
            int b = mpp[temp];
            ans[b].push_back(it);
        }
        
        return ans;
    }
};