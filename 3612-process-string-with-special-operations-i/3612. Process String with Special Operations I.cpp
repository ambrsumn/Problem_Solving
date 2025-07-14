class Solution {
public:
    string processStr(string s) {

        string ans = "";

        for(auto it : s)
        {
            // cout<<it<<" ";
            if(it == '*')
            {
                // cout<<"* ";
                if(ans.length() > 0)ans.pop_back();
            }
            else if(it == '#')
            {
                // cout<<"# ";
                 ans += ans;
            }
            else if(it == '%')
            {
                // cout<<"% "; 
                reverse(ans.begin(), ans.end());
            }
            else 
            {
                // cout<<"char ";
                ans += it;
            }

            // cout<<ans<<endl;
        }

        return ans;
    }
};