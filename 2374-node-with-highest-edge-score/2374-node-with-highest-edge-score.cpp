class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        unordered_map<long long, vector<long long>> mpp;
        
        for(long long i=0; i<edges.size(); i++)
        {
            mpp[edges[i]].push_back(i);
        }
        priority_queue<pair<long long,long long>> pq;
        
        for(auto it : mpp)
        {
            long long sum=0;
            for(auto itt : it.second)
            {
                sum += itt;
            }
            
            pq.push({sum,it.first});
        }
        
        set<long long> st;
        st.insert(pq.top().second);
        long long d = pq.top().first;
        pq.pop();
        
        while(!pq.empty() && pq.top().first==d)
        {
            st.insert(pq.top().second);
            pq.pop();
        }
        
        
        return *st.begin();
    }
};