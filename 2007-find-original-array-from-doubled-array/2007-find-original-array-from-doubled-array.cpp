class Solution {
public:
    
    static bool sortcol(int &a, int &b)
    {
        return abs(a)<abs(b);
    }
    
    vector<int> findOriginalArray(vector<int>& arr) 
    {
        vector<int> ans, temp;
        
        sort(arr.begin(), arr.end(), sortcol);
        
        unordered_map<int,int> mpp;
        
        for(auto it : arr)
            mpp[it]++;
        
        for(auto it : arr)
        {
            if(mpp[it] != 0)
            {
                // cout<<it<<" "<<mpp[it]<<endl;
                
                if(mpp[2*it] == 0)
                    return temp;
                
                ans.push_back(it);
                mpp[it]--;
                
                if(mpp[2*it] == 0)return temp;
                mpp[2*it]--;
            }
        }
        
        return ans;
    }
};