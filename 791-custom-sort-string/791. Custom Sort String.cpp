class Solution {
public:

    string customSortString(string order, string s) {

        string ans = "";

        for(auto it : order)
        {
            for(auto itt : s)
            {
                if(it == itt)ans.push_back(it);
            }
        }

        for(auto it : s)
        {
            auto finder = order.find(it);

            if(finder == string::npos)ans.push_back(it);
        }
        

        return ans;
    }
};