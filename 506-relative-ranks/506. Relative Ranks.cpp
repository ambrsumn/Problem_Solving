class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        vector<string> ans;
        sort(temp.begin(), temp.end());

        map<int, int> mpp;
        int rank = 1;

        for(int i=temp.size()-1; i>=0; i--)
        {
            mpp[temp[i]] = rank;
            rank++;
        }

        for(auto it : score)
        {
            if(mpp[it] == 1)ans.push_back("Gold Medal");
            else if(mpp[it] == 2)ans.push_back("Silver Medal");
            else if(mpp[it] == 3)ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mpp[it]));
        }

        return ans;
        
    }
};