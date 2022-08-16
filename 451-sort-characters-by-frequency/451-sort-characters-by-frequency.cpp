class Solution {
public:
    
    unordered_map<int,int> mpp;
    
    string frequencySort(string s) 
    {
        string ans="";
        
        for(auto it : s)
            mpp[it]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it : mpp)
            pq.push({it.second, it.first});
        
        set<char> st;
        
        while(!pq.empty())
        {
            st.clear();
            
            pair<int,char> pr = pq.top();
            pq.pop();
            st.insert(pr.second);
            // cout<<pr.second<<" "<<pr.first<<endl;
            
            while(!pq.empty() && pq.top().first == pr.first)
            {
                st.insert(pq.top().second);
                pq.pop();    
            }
            
            for(auto it : st)
            {
                for(int i=0; i<pr.first; i++)
                    ans.push_back(it);
            }
        }
        
        return ans;
    }
};