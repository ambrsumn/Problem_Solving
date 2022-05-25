class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) 
    {
        map<int, int> mpp;
        vector<int> vec;
        
        for(int i=0; i<arr.size(); i++)
        {
            mpp[arr[i][0]] = i;
            vec.push_back(arr[i][0]);
        }
        
        sort(vec.begin(), vec.end());
        
        vector<int> ans;
        
        for(int i=0; i<arr.size(); i++)
        {
            int key = arr[i][1];
            
            int d = (lower_bound(vec.begin(), vec.end(), key) - vec.begin());
            
            if(d == vec.size())
            ans.push_back(-1);
            
            else
            {
                int anr = vec[d];
                auto it = mpp.find(anr);
                
                ans.push_back(it->second);
            }
            
        }
        
        return ans;
    }
};