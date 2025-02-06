class Solution {
public:
    int maxArea(vector<int>& vec) 
    {
        int n = vec.size();
        int i=0, j=(n-1);
        
        int mvol=0;
        int curr=0;
        
        
        while(i<j)
        {
            curr = (min(vec[i], vec[j]) * (j-i));
            
            if(curr > mvol)
                mvol = curr;
            
            if(vec[j] <= vec[i])
                j--;
            
            else if(vec[i] < vec[j])
                i++;
        }
        
        return mvol;
    }
};