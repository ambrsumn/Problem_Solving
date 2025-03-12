class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> mpp;

        int i=0, j=0, ans = 0;
        while(j < s.length())
        {
            if(mpp.find(s[j]) == mpp.end())
            {
                ans = max(ans, (j-i+1));
                // cout<<j<<" "<<i<<" "<<ans<<endl;
                mpp[s[j]]++;
            }
            else
            {
                // cout<<"going in ";
                while(i<=j)
                {
                    if(s[i] == s[j])
                    {
                        mpp.erase(s[i]);
                        i++;
                        break;                        
                    }
                    else
                    {
                        mpp.erase(s[i]);
                        i++;
                    }
                }
                mpp[s[j]]++;

                // cout<<i<<endl;
            }

            j++;
        }

        return ans;
    }
};