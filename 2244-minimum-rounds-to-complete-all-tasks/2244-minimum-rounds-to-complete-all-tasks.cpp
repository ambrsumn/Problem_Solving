class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int ans = 0;
        map<int, int> mpp;
        for(auto it : tasks)mpp[it]++;
        
        for(auto it : mpp)
        {
            if(it.second<3 && it.second<2)return -1;
            
            int temp = it.second;
            
            if(temp%3 == 0)ans += temp/3;
            
            else if(temp%3 == 1)ans += (temp/3 + 1);
            
            else ans += temp/3 + 1;
        }
        
        return ans;
    }
};