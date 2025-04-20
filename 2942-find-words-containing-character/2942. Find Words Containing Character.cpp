class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> ans;
        int i=0;
        for(auto it : words)
        {
            int idx = it.find(x);

            if(idx != -1)
            ans.push_back(i);

            i++;
        }
        
        return ans;
        
    }
};