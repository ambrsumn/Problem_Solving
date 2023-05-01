class Solution {
public:
    int isWinner(vector<int>& po, vector<int>& pt) 
    {
        int p1=0, p2=0;
        p1 = po[0];
        
        for(int i=1; i<po.size(); i++)
        {
            if(po[i-1] == 10)
            {
                p1 += 2*po[i];
            }
            
            else if(i-2>=0 && po[i-2] == 10)
            {
                p1 += 2*po[i];
            }
            
            else
            {
                p1 += po[i];
            }
        }
        
        p2 = pt[0];
        
        for(int i=1; i<pt.size(); i++)
        {
            if(pt[i-1] == 10)
            {
                p2 += 2*pt[i];
            }
            
            else if(i-2>=0 && pt[i-2] == 10)
            {
                p2 += 2*pt[i];
            }
            
            else
            {
                p2 += pt[i];
            }
        }
        
        
        if(p1 == p2)return 0;
        
        return p1>p2 ? 1 : 2;
    }
};