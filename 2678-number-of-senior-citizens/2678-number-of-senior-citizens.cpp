class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int ans = 0;
        
        for(auto it : details)
        {
            
            int temp = (it[11] - 48)*10 + (it[12] - 48);
            
            if(temp > 60)ans++;
        }
        
        return ans;
    }
};