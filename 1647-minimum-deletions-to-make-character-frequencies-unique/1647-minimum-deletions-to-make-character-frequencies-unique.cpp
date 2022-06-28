class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> vec;
        map<char, int> mpp;
        
        for(auto it : s)
        {
            mpp[it]++;    
        }
        
        for(auto it : mpp)
        {
            vec.push_back(it.second);
        }
        
        sort(vec.begin(), vec.end());
        vector<int> arr;
        int ans=0;
        
        for(int i=0; i<vec[0]; i++)
            arr.push_back(i);
        
        // for(auto it : vec)
        //     cout<<it<<" ";
        // cout<<endl;
        
        // cout<<vec.size()<<endl;
        // cout<<arr.back()<<endl;
        
        for(int i=0; i<vec.size()-1; i++)
        {
            for(int j=vec[i]+1; j<vec[i+1]; j++)
                arr.push_back(j);
            
            // cout<<arr.back()<<" ";
            
            if(vec[i] == vec[i+1])
            {
                ans += vec[i]-arr.back();
                arr.pop_back();
                
                if(arr.empty())
                    arr.push_back(0);
            }
            
        }
        // cout<<endl;
        
        return ans;
    }
};