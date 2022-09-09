class Solution {
public:
    
    static bool srt(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])return a[1]>b[1];
        
        return a[0]<b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& t) 
    {
        sort(t.begin(), t.end(), srt);
        
        stack<pair<int,int>> st;
        
        int count=0;
        
        for(int i=0; i<t.size(); i++)
        {
            while(!st.empty() && st.top().first < t[i][0] && st.top().second < t[i][1])
            {
                count++;
                st.pop();
            }
            
            st.push({t[i][0], t[i][1]});
        }
        
        return count;
    }
};