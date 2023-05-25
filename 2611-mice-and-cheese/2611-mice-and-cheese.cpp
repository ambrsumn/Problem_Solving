class Solution {
public:
    
// static bool Compare(pair<int,int> p1)
// {
//     if(p1.first >= p1.second)
//     return true;
    
//     return false;
// }
    
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) 
    {
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<reward1.size(); i++)pq.push({reward1[i]-reward2[i], i});
        int ans = 0;
        
            while(!pq.empty() && k>0)
            {
                // cout<<"Y"<<endl;
                ans += reward1[pq.top().second];
                pq.pop();
                k--;
            }
        
            while(!pq.empty())
            {
                // cout<<"Y"<<endl;
                ans += reward2[pq.top().second];
                pq.pop();
                k--;
            }
        
        return ans;
    }
};