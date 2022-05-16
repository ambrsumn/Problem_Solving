class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        sort(special.begin(), special.end());
        
        vector<int> diff;
        
        diff.push_back(special[0]-bottom);
        
        for(int i=1; i<special.size(); i++)
        {
            diff.push_back(special[i]-special[i-1]-1);
        }
        
        diff.push_back(top-special.back());
        
        sort(diff.begin(), diff.end());
        
        
        return diff.back();
        
    }
};