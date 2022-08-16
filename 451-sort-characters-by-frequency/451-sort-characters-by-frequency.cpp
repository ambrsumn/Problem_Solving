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
        
        map<char, int> mppp;
        
        while(!pq.empty())
        {
           mppp.clear();
            
            pair<int,char> pr = pq.top();
            pq.pop();
            mppp[pr.second]++;
            
            while(!pq.empty() && pq.top().first == pr.first)
            {
                mppp[pq.top().second]++;
                pq.pop();    
            }
            
            for(auto it : mppp)
            {
                for(int i=0; i<pr.first; i++)
                    ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};