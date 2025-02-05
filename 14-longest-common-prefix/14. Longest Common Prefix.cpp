class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = strs[0];

        for(int i=1; i<strs.size(); i++)
        {
            int j=0, k=0;
            string temp = strs[i];
            string newAns = "";

            if(temp == "" || ans == "")
            {
                ans = "";
                continue;
            }

            while(j<=ans.length()-1 && k<=temp.length())
            {
                if(ans[j] == temp[k])
                {
                    newAns += ans[j];
                    j++;
                    k++;
                }
                else
                {
                    break;
                }
            }

            ans = newAns;
        }

        return ans;
        
    }
};