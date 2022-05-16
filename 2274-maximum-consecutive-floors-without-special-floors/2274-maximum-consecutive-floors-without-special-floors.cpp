class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        sort(special.begin(), special.end());
        
        vector<int> diff;
        int maxi = (special[0]-bottom);
        
        
        for(int i=1; i<special.size(); i++)
        {
            int newer = (special[i]-special[i-1]-1);
            
            maxi = max(maxi,newer);
            
        }
        
        maxi = max(maxi, (top-special.back()));
        
        return maxi;
        
    }
};