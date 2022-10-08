class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> mpp;
        
        for(auto it : words)
            mpp[it]++;
        
        priority_queue<pair<int,string>> pq;
        
        for(auto it : mpp)
            pq.push({it.second, it.first});
        
        vector<string> ans;
        set<string> st;
        int temp = k;
        
        while(!pq.empty() and k>0)
        {
            st.clear();
            
            int t = pq.top().first;
            int count=0;
            
            while(!pq.empty() && pq.top().first == t)
            {
                // cout<<k<<" "<<pq.top().second<<endl;
                st.insert(pq.top().second);
                pq.pop();
                count++;
            }
            
            for(auto it : st)ans.push_back(it);
            
            k -= count;
        }
        
        while(ans.size()>temp)ans.pop_back();
        
        return ans;
    }
};