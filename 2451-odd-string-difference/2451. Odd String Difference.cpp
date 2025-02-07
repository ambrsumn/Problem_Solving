class Solution {
public:
    string oddString(vector<string>& words) {

        vector<vector<int>> diff;

        for(auto it : words)
        {
            vector<int> temp;
            for(int i=1; i<it.length(); i++)
            {
                temp.push_back(it[i]-it[i-1]);
            }

            diff.push_back(temp);
        }
        int ans = -1;

        for(int i=0; i<diff.size()-1; i++)
        {

            if(i == 0)
            {
                if(diff[i] != diff[i+1])
                {
                ans = i;
                }
            }
            else
            {
                if(diff[i] != diff[i+1] && diff[i] != diff[i-1])
                {
                    ans = i;
                }
            }
        }

        if(ans == -1)ans = diff.size()-1;

        return words[ans];
        
    }
};