class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
    {
        vector<int> vec;
        vector<int> ans;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '|')
                vec.push_back(i);
        }
        
        for(int i=0; i<queries.size(); i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            
            int lb = (upper_bound(vec.begin(), vec.end(), a)-vec.begin())-1;
            
            if(lb==-1)
                lb++;
            
            else if(vec[lb] < a)
                lb++;
            
            int ub = (upper_bound(vec.begin(), vec.end(), b)-vec.begin())-1;
            
            if(ub>lb)
            ans.push_back((vec[ub]-vec[lb]+1)-(ub-lb+1));
            else
                ans.push_back(0);
        }
        
        return ans;
    }
};