class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> mpp;

        for(int i=0; i<strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            mpp[str].push_back(i);
        }

        vector<vector<string>> vec;
        for(auto it : mpp)
        {
            vector<string> temp;
            for(auto itt : it.second)
            {
                temp.push_back(strs[itt]);
            }
            vec.push_back(temp);
        }

        return vec;
    }
};