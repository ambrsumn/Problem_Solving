class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        queue<int> d, r;
        
        for(int i=0; i<senate.length(); i++)
        {
            if(senate[i] == 'R')r.push(i);
            else d.push(i);
        }
        
        while(!d.empty() && !r.empty())
        {
            int di = d.front();
            d.pop();
            
            int ri = r.front();
            r.pop();
            
            if(di < ri)d.push(di+senate.length());
            else r.push(ri+senate.length());
        }
        
        return d.size() < r.size() ? "Radiant" : "Dire";
    }
};